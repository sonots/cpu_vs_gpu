# How to compile

make

# CPU and GPU

```
Intel(R) Xeon(R) CPU E5-2623 v3 @ 3.00GHz
```


```
GeForce GTX TITAN X
```

# Result

```
$ ./cpu # 1 core
Vector size 102400
Elapsed 0.000459
$ ./simd # 1 core
Vector size 102400
Elapsed 0.000102
$ ./gpu
Vector size 102400
Elapsed 0.000066
```

```
$ ./cpu
Vector size 10485760
Elapsed 0.018573
$ ./simd
Vector size 10485760
Elapsed 0.014681
$ ./gpu
Vector size 10485760
Elapsed 0.000116
```

