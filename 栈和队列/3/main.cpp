#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#define MAX_SIZE 5

typedef struct InformationOfCars {
    string ID;
    int iArriveHour, iArriveMin;
} CarInfo;

typedef struct QueueNode {
    InformationOfCars SData;
    QueueNode* SNext;
} QNode;

bool push_car(const CarInfo& carInfo, QNode* SBackNode);

int main(int argc, char** argv) {
    //初始化停车场
    CarInfo SParkVector[MAX_SIZE];

    //初始化等待队列
    QNode *SFrontNode = (QNode*)malloc(sizeof(QNode));
    SFrontNode->SNext = nullptr;
    QNode *SBackNode = SFrontNode;

    int iChoose = -1;
    int iCountPark = 0;
    int iCountWait = 0;
    //加载选项菜单
    while (iChoose != 0) {
        cout << "\n======= 停车场管理系统 =======\n";
        cout << "1. 进入车辆（排队）；\n";
        cout << "2. 离开车辆；\n";
        cout << "3. 打印停车场车辆信息；\n";
        cout << "0. 退出系统。\n";
        cout << "请输入选项：";
        cin >> iChoose;
        switch (iChoose) {
            case 1: {
                CarInfo STmp;
                cout << "请输入车辆车牌号：";
                cin >> STmp.ID;

                //获取当前时间
                time_t now;
                struct tm *tm_now ;
                time(&now) ;
                tm_now = localtime(&now);

                STmp.iArriveMin = tm_now->tm_min;
                STmp.iArriveHour = tm_now->tm_hour;

                if (iCountPark < MAX_SIZE) {
                    SParkVector[iCountPark++] = STmp;
                } else {
                    if (iCountWait == 0) {
                        SBackNode->SData.ID = STmp.ID;
                    } else {
                        push_car(STmp, SBackNode);
                    }
                    iCountWait++;
                }

                break;
            }
            case 2: {
                string ID;
                cout << "请输入离开的车牌号：";
                cin >> ID;

                for (int i = 0; i < iCountPark; ++i) {
                    if (ID == SParkVector[i].ID) {
                        //获取当前时间
                        time_t now;
                        struct tm *tm_now ;
                        time(&now) ;
                        tm_now = localtime(&now);

                        int iTimeConsumption = (tm_now->tm_hour * 60 + tm_now->tm_min)
                                - (SParkVector[i].iArriveHour * 60 + SParkVector[i].iArriveMin);
                        int iHourConsumption = iTimeConsumption / 60;
                        int iMinConsumption = iTimeConsumption % 60;

                        cout << ID << " ：用时" << iHourConsumption << ":" << iMinConsumption
                                << "，收费：RMB" << iTimeConsumption << ".00（每分钟1元）。\n";

                        for (int j = i; j < iCountPark; ++j) {
                            SParkVector[j] = SParkVector[j+1];
                        }
                        iCountPark--;

                        if (iCountWait != 0) {
                            CarInfo STmp;
                            STmp.ID = SFrontNode->SData.ID;
                            SFrontNode = SFrontNode->SNext;

                            //获取当前时间
                            time_t now;
                            struct tm *tm_now ;
                            time(&now) ;
                            tm_now = localtime(&now);

                            STmp.iArriveMin = tm_now->tm_min;
                            STmp.iArriveHour = tm_now->tm_hour;

                            SParkVector[iCountPark++] = STmp;
                        }

                        break;
                    }
                }
                break;
            }
            case 3: {
                for (int i = 0; i < iCountPark; ++i) {
                    cout << SParkVector[i].ID << " ：" << SParkVector[i].iArriveHour << ":" << SParkVector[i].iArriveMin << " 进入；\n";
                }
                break;
            }
        }
    }
}


bool push_car(const CarInfo& carInfo, QNode* SBackNode) {
    QNode *STmp = (QNode*)malloc(sizeof(QNode));
    if (STmp == nullptr)
        return false;

    STmp->SData.ID = carInfo.ID;
    STmp->SNext = nullptr;
    SBackNode->SNext = STmp;

    SBackNode = SBackNode->SNext;
    return true;
}
