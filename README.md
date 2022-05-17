# 如何使用slam相关的库

<div align="center">

| [eigen](https://github.com/liuqian62/lib_use/tree/main/eigen) | [ceres](https://github.com/liuqian62/lib_use/tree/main/ceres) | [g2o](https://github.com/liuqian62/lib_use/tree/main/g2o) | [opencv](https://github.com/liuqian62/lib_use/tree/main/opencv) | [souphus](https://github.com/liuqian62/lib_use/tree/main/sophus)|
| :---: | :---: |  :---: | :---: |:---: |
| 矩阵运算 | 优化 |图优化 | 计算机视觉|李群和李代数|
</div>

how to run 
```bash
sh run_all.sh
```

## 注意事项
* ceres 和g2o使用时需要[cmake](https://github.com/liuqian62/lib_use/tree/main/ceres/cmake)文件夹，并且在CMakeLists.txt中加入
```cmake
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
```
