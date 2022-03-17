# include_directories(..)

# Runtime library sources and build flags.
set(DUNGN_RTL_SOURCES
  dungn.cc
  dungn_custom.cc
  dungn_interceptors.cc)

set(DUNGN_RTL_HEADERS
  dungn.h
  dungn_flags.inc
  dungn_platform.h)

set(DUNGN_COMMON_CFLAGS ${SANITIZER_COMMON_CFLAGS})

append_rtti_flag(OFF DUNGN_COMMON_CFLAGS)
# Prevent clang from generating libc calls.
append_list_if(COMPILER_RT_HAS_FFREESTANDING_FLAG -ffreestanding DUNGN_COMMON_CFLAGS)

# Static runtime library.
add_compiler_rt_component(dungn)

foreach(arch ${DUNGN_SUPPORTED_ARCH})
  set(DUNGN_CFLAGS ${DUNGN_COMMON_CFLAGS})
  append_list_if(COMPILER_RT_HAS_FPIE_FLAG -fPIE DUNGN_CFLAGS)
  add_compiler_rt_runtime(dungn_rt
    STATIC
    ARCHS ${arch}
    SOURCES ${DUNGN_RTL_SOURCES}
            $<TARGET_OBJECTS:RTInterception.${arch}>
            $<TARGET_OBJECTS:RTSanitizerCommon.${arch}>
            $<TARGET_OBJECTS:RTSanitizerCommonLibc.${arch}>
    CFLAGS ${DUNGN_CFLAGS}
    PARENT_TARGET dungn)
  add_sanitizer_rt_symbols(dungn_rt
    ARCHS ${arch}
    EXTRA dungn.syms.extra)
  add_dependencies(dungn
    dungn_rt-${arch}-symbols)
  install(FILES ${COMPILER_RT_OUTPUT_DIR}/libdungn_rt-${arch}.a.syms
    DESTINATION ${COMPILER_RT_LIBRARY_INSTALL_DIR})
endforeach()

set(dungn_abilist_dir ${COMPILER_RT_OUTPUT_DIR}/share)
set(dungn_abilist_filename ${dungn_abilist_dir}/dungn_abilist.txt)
add_custom_target(dungn_abilist ALL
  DEPENDS ${dungn_abilist_filename})
add_custom_command(OUTPUT ${dungn_abilist_filename}
                   VERBATIM
                   COMMAND
                    ${CMAKE_COMMAND} -E make_directory ${dungn_abilist_dir}
                   COMMAND
                     cat ${CMAKE_CURRENT_SOURCE_DIR}/done_abilist.txt
                         ${CMAKE_CURRENT_SOURCE_DIR}/libc_ubuntu1404_abilist.txt
                         > ${dungn_abilist_filename}
                   DEPENDS done_abilist.txt libc_ubuntu1404_abilist.txt)
add_dependencies(dungn dungn_abilist)
install(FILES ${dungn_abilist_filename}
        DESTINATION ${ANGORA_RULE_DIR})

