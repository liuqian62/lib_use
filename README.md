# 如何使用slam相关的库

<div align="center">

| [eigen](https://github.com/liuqian62/lib_use/tree/main/eigen) | [ceres](https://github.com/liuqian62/lib_use/tree/main/ceres) | [g2o](https://github.com/liuqian62/lib_use/tree/main/g2o) | [opencv](https://github.com/liuqian62/lib_use/tree/main/opencv) | [sophus](https://github.com/liuqian62/lib_use/tree/main/sophus)|
| :---: | :---: |  :---: | :---: |:---: |
| 矩阵运算 | 优化 |图优化 | 计算机视觉|李群和李代数|
</div>

how to run 
```bash
sh run_all.sh
```
## 总结
### CMakeLists.txt的编写
* eigen

```cmake
include_directories("/usr/include/eigen3")
```
* ceres

```cmake
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

target_link_libraries(xxx ${CERES_LIBRARIES})
```
* g2o

```cmake
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})

target_link_libraries(xxx ${G2O_CORE_LIBRARY} ${G2O_STUFF_LIBRARY})
```
* OpenCV


`注意使用opencv提取SIFT和 SURF特征时，opencv版本要低于3.4.1或者contrib版本，后续版本因专利问题被移除了，使用时xfeature2d好像也很容易报错`
```cmake
# set(CMAKE_PREFIX_PATH "/home/rich/third/opencv-3.4.0/release/installed/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(xxx ${OpenCV_LIBS})
```
* sophus
```cmake
find_package(Sophus REQUIRED)
target_link_libraries(xxx Sophus::Sophus)
```
## 注意事项
* ceres 和g2o使用时需要[cmake](https://github.com/liuqian62/lib_use/tree/main/ceres/cmake)文件夹，并且在CMakeLists.txt中加入
```cmake
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
```
