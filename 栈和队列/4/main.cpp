#include <iostream>
#include <string>
using namespace std;
typedef struct PeopleNode {
    string sName; //不能为空
    struct PeopleNode* SNext;
} Node;

int main() {
    string sWindows[7];
    for (int i = 1; i < 7; ++i) {
        sWindows[i] = "空";
    }

    Node* SFundFront = (Node*)malloc(sizeof(Node));
    SFundFront->SNext = nullptr;
    Node* SFundBack = SFundFront;

    Node* SCardFront = (Node*)malloc(sizeof(Node));
    SCardFront->SNext = nullptr;
    Node* SCardBack = SCardFront;

    Node* SFinanceFront = (Node*)malloc(sizeof(Node));
    SFinanceFront->SNext = nullptr;
    Node* SFinanceBack = SFinanceFront;

    int iFundCount = 0, iCardCount = 0, iFinanceCount = 0;
    int iChoose = -1;

    while (iChoose != 0) {
        cout << "\n====== 银行营业模拟 ======\n";
        cout << "1. 顾客办理业务（排队）；\n";
        cout << "2. 顾客离开；\n";
        cout << "3. 显示窗口状态；\n";
        cout << "0. 退出系统\n";
        cout << "请输入：";
        cin >> iChoose;
        switch (iChoose) {
            case 1: {
                string sName;
                int iType;
                cout << "请输入姓名:";
                cin >> sName;
                cout << "请输入办理业务（1.公积金、2.银行卡、3.理财卡）：";
                cin >> iType;
                Node* STmp = (Node*)malloc(sizeof(Node));
                STmp->sName = sName;
                STmp->SNext = nullptr;
                switch (iType) {
                    case 1: {
                        if (sWindows[1] != "空") {
                            if (iFundCount != 0) {
                                SFundBack->SNext = STmp;
                            } else {
                                SFundBack->sName = sName;
                                iFundCount++;
                            }
                        } else {
                            sWindows[1] = sName + "  公积金";
                        }

                        break;
                    }
                    case 2: {
                        bool bFlg = false;
                        for (int i = 2; i < 5; ++i) {
                            if (sWindows[i] == "空") {
                                bFlg = true;
                                sWindows[i] = sName + "  银行卡";
                                break;
                            }
                        }
                        if (!bFlg) {
                            if (iCardCount != 0) {
                                SCardBack->SNext = STmp;
                            } else {
                                SCardBack->sName = sName;
                                iCardCount++;
                            }
                        }

                        break;
                    }
                    case 3: {
                        bool bFlg1 = false;
                        for (int i = 5; i < 7; ++i) {
                            if (sWindows[i] == "空") {
                                bFlg1 = true;
                                sWindows[i] = sName + "  理财卡";
                                break;
                            }
                        }
                        if (!bFlg1) {
                            bool bFlg2 = false;
                            for (int i = 2; i < 5; ++i) {
                                if (sWindows[i] == "空") {
                                    bFlg2 = true;
                                    sWindows[i] = sName + "  理财卡";
                                    break;
                                }
                            }
                            if (!bFlg2) {
                                if (iFinanceCount != 0) {
                                    SFinanceBack->sName = sName;
                                } else {
                                    SFinanceBack->SNext = STmp;
                                    iFinanceCount++;
                                }
                            }
                        }

                        break;
                    }
                    default:{}
                }

                break;
            }
            case 2: {
                int iPos;
                cout << "请输入离开顾客所在窗口：";
                cin >> iPos;
                sWindows[iPos] = "空";
                if (iPos == 1) {
                    if (iFundCount != 0) {
                        sWindows[1] = SFundFront->sName + "  公积金";
                        SFundFront = SFundFront->SNext;
                        iFundCount--;
                    }
                } else if (iPos > 1 && iPos < 5) {
                    if (iCardCount != 0) {
                        sWindows[iPos] = SCardFront->sName + "  银行卡";
                        SCardFront = SCardFront->SNext;
                        iCardCount--;
                    } else if (iFinanceCount != 0) {
                        sWindows[iPos] = SFinanceFront->sName + "  理财卡";
                        SFinanceFront = SFinanceFront->SNext;
                        iFinanceCount--;
                    }
                } else {
                    if (iFinanceCount != 0) {
                        sWindows[iPos] = SFinanceFront->sName + "  理财卡";
                        SFinanceFront = SFinanceFront->SNext;
                        iFinanceCount--;
                    }
                }

                break;
            }
            case 3: {
                for (int i = 1; i < 7; ++i) {
                    cout << "第" << i << "个窗口： " << sWindows[i] << "\n";
                }
                break;
            }
            default:{}
        }
    }

    return 0;
}