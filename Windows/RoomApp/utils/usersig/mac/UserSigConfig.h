#ifndef __USER_SIG_CONFIG_H__
#define __USER_SIG_CONFIG_H__

#include <string>
#include <vector>
#include <stdint.h>

class UserSigConfig {
private:
    UserSigConfig(){}
    ~UserSigConfig(){}
public:
    static UserSigConfig& instance(){
        static UserSigConfig uniqueInstance;
        return uniqueInstance;
    }
    int GetSDKAPPID() {
        return SDKAPPID_;
    }
    std::string GetSecretKey() {
        return SecretKey_;
    }

    /**
    * ��Ѷ�� SDKAppId����Ҫ�滻Ϊ���Լ��˺��µ� SDKAppId��
    *
    * ������Ѷ��ʵʱ����Ƶ[����̨](https://console.cloud.tencent.com/rav ) ����Ӧ�ã����ɿ��� SDKAppId��
    * ������Ѷ���������ֿͻ���Ψһ��ʶ��
    */
    const int SDKAPPID_ = 0;

    /**
    * ����ǩ���õļ�����Կ����ȡ�������£�
    *
    * step1. ������Ѷ��ʵʱ����Ƶ[����̨](https://console.cloud.tencent.com/rav )�������û��Ӧ�þʹ���һ����
    * step2. ��������Ӧ�ã�����һ���ҵ����������֡����֡�
    * step3. ������鿴��Կ����ť���Ϳ��Կ������� UserSig ʹ�õļ��ܵ���Կ�ˣ��뽫�俽�������Ƶ����µı�����
    *
    * ע�⣺�÷����������ڵ���Demo����ʽ����ǰ�뽫 UserSig ����������ԿǨ�Ƶ����ĺ�̨�������ϣ��Ա��������Կй¶���µ��������á�
    * �ĵ���https://cloud.tencent.com/document/product/647/17275#Server
    */
    const std::string SecretKey_ = "";
};

#endif
