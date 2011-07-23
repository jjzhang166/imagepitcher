// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "twitpicuploader.h"
#include "oauth.h"

#pragma once

class CMainDlg : 
  public CDialogImpl<CMainDlg>, 
  public CUpdateUI<CMainDlg>,
  public CMessageFilter, 
  public CIdleHandler
{
public:
  enum { IDD = IDD_MAINDLG };

  CMainDlg();
  virtual ~CMainDlg() {};

  virtual BOOL PreTranslateMessage(MSG* pMsg);
  virtual BOOL OnIdle();

  BEGIN_UPDATE_UI_MAP(CMainDlg)
  END_UPDATE_UI_MAP()

  BEGIN_MSG_MAP(CMainDlg)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
    COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
    COMMAND_ID_HANDLER(IDOK, OnOK)
    COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    COMMAND_HANDLER(IDC_BUTTON_PIN, BN_CLICKED, OnBnClickedButtonPin)
  END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

  LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
  LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
  LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
  LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
  LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

  LRESULT OnBnClickedButtonPin(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

  void CloseDialog(int nVal);

private:
  CTwitterOAuth OAuth;
  CTwitpicUploader Uploader;
};
