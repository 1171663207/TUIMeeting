#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <VideoRenderViewInfo.h>
#include "TUIRoomCore.h"
#include "ui_VideoRenderView.h"

class VideoRenderView : public QWidget
{
    Q_PROPERTY(bool is_talking READ IsTalking)
    Q_OBJECT

public:
    VideoRenderView(QWidget *parent);
    ~VideoRenderView();

    void InitUi();
    void InitConnect();

    std::string GetUserId();
    void UpdateUserInfo(const TUIUserInfo& user_info);
    void StartPreview();
    void StopPreview();
    void RemoveUser();

    liteav::TXView GetPlayWindow();
    bool IsOnCurrentPage();
    void PopVideoTip(bool top);
    void ShowVideoTip(bool show, bool is_minimized=false);
    void InitMainVideo();
    void UserStartScreenShare(const std::string& user_id); // ��ʼ��Ļ����
    void UserStopScreenShare();
    void ShowUserVideo(const std::string& user_id);  // ��ʼ������Ƶ
    void StopUserVideo(const std::string& user_id);  // ֹͣ������Ƶ
    void ScreenShareOnStage(const std::string& user_id);  // �����б�����ʾ��Ļ����
    void ReviveUserVideo(); // �������ϵĲ���
    void ReviveVideo();     // �����б��ڵĲ���
protected:
    void resizeEvent(QResizeEvent* event);
    void showEvent(QShowEvent* event);
    void hideEvent(QHideEvent* event);
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
public slots:
    void SlotOnFirstVideoFrame(const QString& user_id, const TUIStreamType streamType);
    void SlotOnUserVoiceVolume(const QString& user_id, int volume);
    void SlotReviveScreenShare(const std::string& user_id);
    void OnNetStatistics(const liteav::TRTCStatistics& statis);
    bool IsTalking() const;
signals:
    void SignalShowVideoOnMainScreen(const std::string& user_id);
    void SignalReviveVideo(const std::string& user_id);
    void SignalInsertScreenOnStage(const std::string& user_id);
    void SignalReviveScreenShare(const std::string& user_id);
private:
    Ui::VideoRenderView* ui_;
    QLabel* pLabel = NULL;

    VideoRenderViewInfo* video_head_ = nullptr;
    TUIUserInfo user_info_;
    bool is_local_user = false;
    bool is_talking_ = false;
    bool is_playing_ = false;
    bool is_mainwindow_minimized_ = false;
    bool is_on_current_page_ = false;
    bool is_main_video_ = false;          // �Ƿ�Ϊ����Ƶҳ����
    bool is_show_on_main_screen_ = false; // ���ϴ��ڣ��Ƿ���������Ƶҳ������ʾ
    bool is_user_screen_sharing_ = false; // ʹ���û�������Ļ����
    bool is_screen_on_stage_ = false;     // ��Ļ������ʾ������
};
