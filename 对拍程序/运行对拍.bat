@echo off
cd C:\acm\���ĳ���
g++ ���Ĵ���.cpp -o c:/acm/workexe/���Ĵ���.exe -std=c++11 -static -O2
g++ ����������.cpp -o c:/acm/workexe/����������.exe -std=c++11 -static -O2
g++ ��������.cpp -o c:/acm/workexe/��������.exe -std=c++11 -static -O2

for /l %%i in (1, 1, 10) do (
    c:/acm/workexe/����������.exe %random% >C:\acm\workexe\in.txt
    c:/acm/workexe/���Ĵ���.exe <C:\acm\workexe\in.txt >C:\acm\workexe\out.txt
    c:/acm/workexe/��������.exe <C:\acm\workexe\in.txt >C:\acm\workexe\stdout.txt
    fc C:\acm\workexe\out.txt C:\acm\workexe\stdout.txt
    if errorlevel 1 (
        echo WA
        goto END
    )
)
echo AC
:END