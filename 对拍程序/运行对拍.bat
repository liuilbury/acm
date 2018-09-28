@echo off
cd C:\acm\对拍程序
g++ 对拍代码.cpp -o c:/acm/workexe/对拍代码.exe -std=c++11 -static -O2
g++ 数据生成器.cpp -o c:/acm/workexe/数据生成器.exe -std=c++11 -static -O2
g++ 暴力代码.cpp -o c:/acm/workexe/暴力代码.exe -std=c++11 -static -O2

for /l %%i in (1, 1, 10) do (
    c:/acm/workexe/数据生成器.exe %random% >C:\acm\workexe\in.txt
    c:/acm/workexe/对拍代码.exe <C:\acm\workexe\in.txt >C:\acm\workexe\out.txt
    c:/acm/workexe/暴力代码.exe <C:\acm\workexe\in.txt >C:\acm\workexe\stdout.txt
    fc C:\acm\workexe\out.txt C:\acm\workexe\stdout.txt
    if errorlevel 1 (
        echo WA
        goto END
    )
)
echo AC
:END