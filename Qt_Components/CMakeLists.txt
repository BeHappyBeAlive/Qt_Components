#设置cmake版本号
cmake_minimum_required(VERSION 3.28.0)

#设置工程名称
project(Qt_CMake_Demo)
set(CMAKE_PREFIX_PATH "D:/program/selfsrc/Qt_sdk_5.14.2/5.14.2/msvc2017_64")
#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#打开全局moc,设置自动生成moc文件，一定要设置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_MOC_OPTIONS -o ${CMAKE_CURRENT_BINARY_DIR}/generated/moc)
#打开全局rcc，非必须，如需打开，注意修改33行的qrc文件名
set(CMAKE_AUTORCC ON)

#查找需要的Qt库文件，最好每一个库都要写，Qt也会根据依赖关系自动添加
find_package(Qt5Widgets REQUIRED) 
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

#查找当前文件夹中的所有源代码文件，也可以通过Set命令将所有文件设置为一个变量
FILE(GLOB SRC_FILES "./*.cpp")
#查找设置当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h")

#添加资源文件，非必须，一旦采用，注意修改相应的qrc文件名
qt5_add_resources(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/qt_resources/resource.qrc)

#创建工程文件
add_executable(Qt_CMake_Demo ${SRC_FILES} ${HEAD_FILES} ${RESOURCES})

#添加Qt5依赖项
target_link_libraries(Qt_CMake_Demo PUBLIC Qt5::Widgets Qt5::Core Qt5::Gui)

# 设置 DLL 文件路径
set(QT_DLL_DIR "${CMAKE_PREFIX_PATH}/bin")

# 查找所有 Qt DLL 文件
file(GLOB QT_DLL_FILES
		"${QT_DLL_DIR}/Qt5Widgets.dll"
		"${QT_DLL_DIR}/Qt5Core.dll"
		"${QT_DLL_DIR}/Qt5Gui.dll"
		"${QT_DLL_DIR}/Qt5Widgetsd.dll"
		"${QT_DLL_DIR}/Qt5Cored.dll"
		"${QT_DLL_DIR}/Qt5Guid.dll"
)

# 复制 DLL 文件到输出目录
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QT_DLL_FILES}
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)
if (WIN32)
  set(QT_PLATFORMS_DIR "${CMAKE_PREFIX_PATH}/plugins/platforms")
	# 查找所有 Qt DLL 文件
	file(GLOB QT_PLATFORM_FILES
			"${QT_PLATFORMS_DIR}/qwindows.dll"
			"${QT_PLATFORMS_DIR}/qwindowsd.dll"
	)
	# 复制平台插件
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E make_directory
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms"
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
				${QT_PLATFORM_FILES}
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms"
	)
endif()
