```flow
s=>start: 开始
o1=>operation: 数据预处理
o2=>operation: 数据格式化
o3=>operation: 获得字体数据
o4=>operation: 字体展示输出
o5=>operation: 字体编码
e=>end: 结束

s->o1->o2->o3->o4->o5->e
```

```flow
s=>start: 开始
o1=>operation: 读取数据文件
o2=>operation: 数据文件预处理
o3=>operation: 数据文件格式化
o4=>operation: 字体解码
o5=>operation: 数据分析: 取单位元
c1=>condition: 是否是字幕
c2=>condition: 是否静态
o6=>operation: 4x4 字体查表
o7=>operation: 数据拼接
o8=>operation: 5x8 字体查表
o9=>operation: 数据拼接
oa=>operation: 字符位移
ob=>operation: 视频解码
c3=>condition: 数据分析是否完成
oc=>operation: 视频编码
e=>end: 结束

s->o1->o2->o3->o4->o5->c1

c1(yes)->c2

c2(yes)->o6->o7->c3
c2(no)->o8->o9->oa->c3

c1(no)->ob->c3

c3(yes)->oc->e
c3(no)->o5
```

```flow
s=>start: 开始
o1=>operation: 驱动程序安装
o2=>operation: 驱动程序连接
o3=>operation: 预读取视频数据
o4=>operation: 读取视频数据 : 取单位元
c1=>condition: 是否告警状态
o5=>operation: 告警数据解码
o6=>operation: 告警信息播放
o7=>operation: 视频数据解码
o8=>operation: 视频播放
c2=>condition: 是否结束
o9=>operation: 驱动程序关闭
e=>end: 结束

s->o1->o2->o3->o4->c1

c1(yes)->o5->o6->c1
c1(no)->o7->o8->c2

c2(yes)->o9->e
c2(no)->o4
```