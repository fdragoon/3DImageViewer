
三维图像重建程序
=======
本程序旨在实现三维图像的显示和交互。

程序要求
-------
1. [VTK 6.3.0](http://www.vtk.org/)
2. [CMake](https://cmake.org/)

使用方法
-------
### 调用方式
    Homework.exe Number Folder
### 参数说明
> Number :功能函数
> 
> > 1   :vtkImageViewer3类实现
>
> > 2   :vtkImagePlaneWidget3+vtkClickCallback实现
>
> Folder :图像文件夹
>
> > 要求为无压缩的DICOM系列文件，暂不支持单个DICOM文件包含多图像的格式。

