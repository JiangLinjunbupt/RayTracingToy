#项目名，默认为目录名
GET_DIR_NAME(DIRNAME)
set(TARGET_NAME ${DIRNAME})
#多个源文件用 [空格] 分隔
#如：set(STR_TARGET_SOURCES "main.cpp src_2.cpp")
file(GLOB ALL_SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)
set(STR_TARGET_SOURCES "")
foreach(SOURCE ${ALL_SOURCES})
	set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${SOURCE}")
endforeach(SOURCE ${ALL_SOURCES})
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/Material.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/OpMaterial.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/Lambertian.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/Metal.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/Dielectric.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/Light.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/Isotropic.h")
set(STR_TARGET_SOURCES "${STR_TARGET_SOURCES} ${CMAKE_SOURCE_DIR}/include/RayTracing/MatVisitor.h")
#多个库文件用 [空格] 分隔，如果为空，就输入[一个空格]
#如：set(STR_TARGET_LIBS "lib1.lib lib2.lib")
set(STR_TARGET_LIBS "HeapObj Math RT_Texture")

SETUP_PROJECT(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} ${STR_TARGET_LIBS})