# include_directories(..)

# Runtime library sources and build flags.
set(AIBAR_RTL_SOURCES
  aibar.cc
  aibar_custom.cc
  aibar_interceptors.cc)

set(AIBAR_RTL_HEADERS
  aibar.h
  aibar_flags.inc
  aibar_platform.h)

set(AIBAR_COMMON_CFLAGS ${SANITIZER_COMMON_CFLAGS})

append_rtti_flag(OFF AIBAR_COMMON_CFLAGS)
# Prevent clang from generating libc calls.
append_list_if(COMPILER_RT_HAS_FFREESTANDING_FLAG -ffreestanding AIBAR_COMMON_CFLAGS)

# Static runtime library.
add_compiler_rt_component(aibar)

foreach(arch ${AIBAR_SUPPORTED_ARCH})
  set(AIBAR_CFLAGS ${AIBAR_COMMON_CFLAGS})
  append_list_if(COMPILER_RT_HAS_FPIE_FLAG -fPIE AIBAR_CFLAGS)
  add_compiler_rt_runtime(aibar_rt
    STATIC
    ARCHS ${arch}
    SOURCES ${AIBAR_RTL_SOURCES}
            $<TARGET_OBJECTS:RTInterception.${arch}>
            $<TARGET_OBJECTS:RTSanitizerCommon.${arch}>
            $<TARGET_OBJECTS:RTSanitizerCommonLibc.${arch}>
    CFLAGS ${AIBAR_CFLAGS}
    PARENT_TARGET aibar)
  add_sanitizer_rt_symbols(aibar_rt
    ARCHS ${arch}
    EXTRA aibar.syms.extra)
  add_dependencies(aibar
    aibar_rt-${arch}-symbols)
  install(FILES ${COMPILER_RT_OUTPUT_DIR}/libaibar_rt-${arch}.a.syms
    DESTINATION ${COMPILER_RT_LIBRARY_INSTALL_DIR})
endforeach()

set(aibar_abilist_dir ${COMPILER_RT_OUTPUT_DIR}/share)
set(aibar_abilist_filename ${aibar_abilist_dir}/aibar_abilist.txt)
add_custom_target(aibar_abilist ALL
  DEPENDS ${aibar_abilist_filename})
add_custom_command(OUTPUT ${aibar_abilist_filename}
                   VERBATIM
                   COMMAND
                    ${CMAKE_COMMAND} -E make_directory ${aibar_abilist_dir}
                   COMMAND
                     cat ${CMAKE_CURRENT_SOURCE_DIR}/done_abilist.txt
                         ${CMAKE_CURRENT_SOURCE_DIR}/libc_ubuntu1404_abilist.txt
                         > ${aibar_abilist_filename}
                   DEPENDS done_abilist.txt libc_ubuntu1404_abilist.txt)
add_dependencies(aibar aibar_abilist)
install(FILES ${aibar_abilist_filename}
        DESTINATION ${ANGORA_RULE_DIR})

