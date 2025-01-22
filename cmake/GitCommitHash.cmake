# 定义函数，用于获取 Git 版本信息
function(get_git_info OUTPUT_VERSION OUTPUT_COMMIT OUTPUT_BRANCH)
    # 查找 Git
    find_package(Git REQUIRED)

    # 获取 Git 当前的版本号（commit hash）
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_COMMIT_HASH
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # 获取当前分支名称
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_BRANCH_NAME
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # 拼接版本信息为 "BranchName-CommitHash"
    set(GIT_VERSION "${GIT_BRANCH_NAME}-${GIT_COMMIT_HASH}")

    # 将结果返回到调用者变量
    set(${OUTPUT_VERSION} "${GIT_VERSION}" PARENT_SCOPE)
    set(${OUTPUT_COMMIT} "${GIT_COMMIT_HASH}" PARENT_SCOPE)
    set(${OUTPUT_BRANCH} "${GIT_BRANCH_NAME}" PARENT_SCOPE)
endfunction()