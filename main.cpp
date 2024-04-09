#include <iostream>
#include "I8H_SDK.h"

extern "C" {
void CALLBACK ExceptionCallBack(DWORD dwType, HANDLE hUserId, HANDLE hHandle, LPVOID lpUser) {
    std::wcout << "处理异常回调" << std::endl;
// 处理异常回调
}

void CALLBACK AlarmDataCallBack(HANDLE hUserId, HANDLE hAlarmHandle, LONG lCommand, LPVOID lpAlarmInfo, DWORD dwAlarmInfoLen, LPVOID lpUser) {
    std::wcout << "处理报警回调" << std::endl;

// 处理报警回调
}
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    // 初始化SDK
    I8H_INIT_PARAM initParam;
    initParam.bAsync = FALSE;
    I8H_SDK_Initv2(&initParam);
    LPVOID lpUser =  NULL;
    // 设置回调函数
    I8H_SDK_SetExceptionCallBack(ExceptionCallBack,lpUser );
    I8H_SDK_SetAlarmDataCallBack(AlarmDataCallBack, lpUser);

    // 登录设备
    HANDLE hUserId;
    hUserId = I8H_SDK_Login("192.168.1.100", 8000, "admin", "password", NULL);
    if (hUserId == NULL) {
        std::wcout << "登录设备失败" << std::endl;
        return -1;
    }

    // 其他操作...

    // 关闭SDK
    I8H_SDK_Cleanup();

    return 0;
}
