#pragma once
#include <QFile>
#include <QString>

// ����App����
static constexpr char kAppName[] = "RoomApp";
static constexpr char kRoomType[] = "Room_";

// ��Ļ����ͼƬ�Ŀ��
static constexpr int kShareItemWidth  = 200;
static constexpr int kShareItemHeight = 150;
static constexpr int kShareItemSpace  = 30;
static constexpr int kShareItemMargin = 40;
static constexpr int kShareIconWidth  = 80;
static constexpr int kShareIconHeight = 80;

// ��Ա�б�Ĳ�����1���� 2����Ƶ 3����̨ 4T��
enum class MemberOperate {
    kMuteMicrophone = 1,
    kMuteCamera = 2,
    kOnStage = 3,
    kKickOffUser = 4,
    kAgreeSpeak = 5,
    kDisAgreeSpeak = 6,
    kForbidSpeak = 7,
    kForbidMicrophone   = 8,
    kForbidCamera = 9
};

enum class LoginError {
    kNoError = 0,
    kGetAppIdFail = 1,
    kUserVerifyByPictureFail = 2,
    kUserLoginByCodeFail = 3,
    kUserLoginByTokenFail = 4,
    kUserLogoutFail = 5,
    kUserDeleteFail = 6,
    kUserUpdateFail = 7,
    kUserQueryFail = 8,
};

enum class MemberStatus {
    kStageUp = 0,
    kInvited = 1,
    kApplied = 2,
    kStageDown = 3,
};

enum class StageListDirection {
    kHorDirection = 1,  //ˮƽ
    kVerDirection = 2   //��ֱ
};

enum class Language {
    kChinese = 0,  // ����
    kEnglish = 1   // Ӣ��
};

enum TXMessageType {
    kNoButton     =   0x0000,
    kOk           =   0x0001,
    kCancel       =   0x0010,
    kLeaveRoom    =   0x0100,
    kDestoryRoom  =   0x1000
};

class NetToolTip {
 public:
    int app_cpu = 0;    // ��ǰApp CPUռ����
    int rtt = 0;        // ������ʱ
    int downLoss = 0;   // ���ж�����
};
struct UserNetQualityInfo {
	///�û� ID
	std::string user_id;
	///�����������μ� TRTCTypeDef.h �� TRTCQuality ö��
	int quality;
    UserNetQualityInfo() : quality(0) {}
};

// ��¼�û���Ϣ
struct UserLoginInfo {
    std::string user_id;
    std::string user_sig;
    std::string name;
    int sdk_app_id;

    UserLoginInfo() 
        : sdk_app_id(0) {
    }
};

#define LOAD_STYLE_SHEET(path) {\
	QString qss;\
	QFile qssFile(path);\
	qssFile.open(QFile::ReadOnly);\
	if (qssFile.isOpen())\
	{\
		qss = QLatin1String(qssFile.readAll());\
		this->setStyleSheet(qss);\
		qssFile.close();\
	}\
}

#define DELETE_OBJECT(obj) {\
    if (obj != nullptr) {\
        delete obj;\
        obj = nullptr;\
    }\
}
