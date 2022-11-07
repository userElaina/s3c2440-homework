<!-- [toc] -->

### 硬件性能测试

#### 测试环境

##### 编译

**操作系统**: GNU/Linux x86_64
**内核版本**: 5.15.74-3-MANJARO
**CPU**: AMD Ryzen 9 5950X 16-Core Processor
**编译器**: `arm-linux-gcc`
**编译器版本**: 3.4.6
**编译命令**:

```sh
arm-linux-gcc fps_test.c -o fps_test
```

##### 运行

**操作系统**: GNU/Linux arm
**CPU**: S3C2440A
**运行命令**:

```sh
./fps_test
```

#### 测试项

8x8点阵 最大帧率.

数码管 最大帧率.

#### 测试步骤

使用程序逐渐提高输出帧率.

#### 预期结果

最大帧率 $F_{\rm ps}>10\rm Hz$ 即帧之间的最低间隔时间 $T_{\rm wait} < 100 \rm ms.$

#### 测试结果与分析

![](./t0.png)

$1500{\rm ms}\leqslant T_{\rm wait},$ 一切正常；
$500{\rm ms}\leqslant T_{\rm wait}<1500\rm ms,$ 有概率发生错误；
$T_{\rm wait}<500\rm ms,$ 一定发生错误。

#### 是否达到预期

否.

#### 总结

程序应该保证 $1500{\rm ms}\leqslant T_{\rm wait}.$

### 配置文件测试

#### 测试环境

##### 解释运行

**操作系统**: GNU/Linux x86_64
**内核版本**: 5.15.74-3-MANJARO
**CPU**: AMD Ryzen 9 5950X 16-Core Processor
**解释器**: `python3`
**解释器版本**: 3.9.13
**命令**:

```sh
python conf_test.py
```

#### 测试项

配置文件正确性.

#### 测试步骤

使用程序读取并编码配置文件.

#### 预期结果

配置文件正确.

#### 测试结果与分析

![](./t1.png)

配置文件正确.

#### 是否达到预期

是.

#### 总结

配置文件正确.

### 数据文件显示测试

#### 测试环境

##### 编译

**操作系统**: GNU/Linux x86_64
**内核版本**: 5.15.74-3-MANJARO
**CPU**: AMD Ryzen 9 5950X 16-Core Processor
**编译器**: `arm-linux-gcc`
**编译器版本**: 3.4.6
**编译命令**:

```sh
arm-linux-gcc v_test.c -o v_test
```

##### 运行

**操作系统**: GNU/Linux arm
**CPU**: S3C2440A
**运行命令**:

```sh
./v_test
```

#### 测试项

数据文件显示正确性.

#### 测试步骤

在 UP-CUP-S3C2440 上使用程序读取并显示数据文件.

#### 预期结果

能正常播放文字和视频.

#### 测试结果与分析

![](./t2.png)

能正常播放文字和视频.

#### 是否达到预期

是.

#### 总结

数据文件显示正确.

### 数据文件生成测试

#### 测试环境

##### 依赖安装

**操作系统**: GNU/Linux x86_64
**内核版本**: 5.15.74-3-MANJARO
**CPU**: AMD Ryzen 9 5950X 16-Core Processor

```sh
sudo pacman -Syu gcc opencv vtk hdf5 pkgconf
```

##### 编译运行

**操作系统**: GNU/Linux x86_64
**内核版本**: 5.15.74-3-MANJARO
**CPU**: AMD Ryzen 9 5950X 16-Core Processor
**编译器**: `gcc`
**编译器版本**: 12.2.0
**编译命令**:

```sh
g++ "badapple.cpp" -o "badapple.out" -w -g -O3 -static-libgcc `pkgcon --cflags --libs opencv4`
./badapple.out
```

#### 测试项

数据文件生成正确性.

#### 测试步骤

使用程序读取, 编码并以 ASCII-ART 形式显示数据文件.

#### 预期结果

能正常以 ASCII-ART 形式播放文字和视频.

#### 测试结果与分析

![](./t3.png)

能正常以 ASCII-ART 形式播放文字和视频.

#### 是否达到预期

是.

#### 总结

数据文件生成正确.
