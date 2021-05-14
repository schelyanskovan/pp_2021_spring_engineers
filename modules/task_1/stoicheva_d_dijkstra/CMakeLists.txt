get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

<<<<<<< HEAD
if ( USE_SEQ )
    set(ProjectId "${ProjectId}_seq")
    project( ${ProjectId} )
    message( STATUS "-- " ${ProjectId} )
=======
if (USE_SEQ)
    set(ProjectId "${ProjectId}_seq")
    project(${ProjectId})
    message(STATUS "-- " ${ProjectId})
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246

    file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h)

    set(PACK_LIB "${ProjectId}_lib")
<<<<<<< HEAD
    add_library(${PACK_LIB} STATIC ${ALL_SOURCE_FILES} )

    add_executable( ${ProjectId} ${ALL_SOURCE_FILES} )
=======
    add_library(${PACK_LIB} STATIC ${ALL_SOURCE_FILES})

    add_executable(${ProjectId} ${ALL_SOURCE_FILES})
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246

    target_link_libraries(${ProjectId} ${PACK_LIB})
    target_link_libraries(${ProjectId} gtest gtest_main)

    enable_testing()
    add_test(NAME ${ProjectId} COMMAND ${ProjectId})

<<<<<<< HEAD
    if( UNIX )
=======
    if (UNIX)
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246
        foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
            string(FIND ${SOURCE_FILE} ${PROJECT_BINARY_DIR} PROJECT_TRDPARTY_DIR_FOUND)
            if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1)
                list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
            endif ()
        endforeach ()

        find_program(CPPCHECK cppcheck)
        add_custom_target(
                "${ProjectId}_cppcheck" ALL
                COMMAND ${CPPCHECK}
                --enable=warning,performance,portability,information,missingInclude
                --language=c++
                --std=c++11
                --error-exitcode=1
                --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
                --verbose
                --quiet
                ${ALL_SOURCE_FILES}
        )
<<<<<<< HEAD
    endif( UNIX )
=======
    endif (UNIX)
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246

    SET(ARGS_FOR_CHECK_COUNT_TESTS "")
    foreach (FILE_ELEM ${ALL_SOURCE_FILES})
        set(ARGS_FOR_CHECK_COUNT_TESTS "${ARGS_FOR_CHECK_COUNT_TESTS} ${FILE_ELEM}")
    endforeach ()

    add_custom_target("${ProjectId}_check_count_tests" ALL
            COMMAND "${Python3_EXECUTABLE}"
            ${CMAKE_SOURCE_DIR}/scripts/check_count_tests.py
            ${ProjectId}
            ${ARGS_FOR_CHECK_COUNT_TESTS}
<<<<<<< HEAD
    )
else( USE_SEQ )
    message( STATUS "-- ${ProjectId} - NOT BUILD!"  )
endif( USE_SEQ )
=======
            )
else (USE_SEQ)
    message(STATUS "-- ${ProjectId} - NOT BUILD!")
endif (USE_SEQ)
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246
