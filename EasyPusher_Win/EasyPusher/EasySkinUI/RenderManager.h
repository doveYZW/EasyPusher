/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
	Author: Gavin@easydarwin.org
*/
#ifndef RENDER_HEAD_FILE
#define RENDER_HEAD_FILE

#pragma once

#include "EasySkinUI.h"

class CImageEx;

//��Դ�ṹ
struct tagImageInfo
{
	CImageEx		*pImage;
	int				nRef;
};

//////////////////////////////////////////////////////////////////////////

class  CUIRenderManager
{
protected:
	HFONT								m_hDefaultFont;			//Ĭ������
	HINSTANCE							m_hResInstance;			//��Դ���
	map<LPCTSTR,tagImageInfo*>			m_ArrayImage;			//ͼƬ����
	vector<HFONT>						m_ArrayFont;			//�������

public:
	CUIRenderManager(void);
	~CUIRenderManager(void);

	//��������
public:
	static CUIRenderManager*GetInstance();

	//��ȡ����
public:
	HFONT GetDeaultFont(){return m_hDefaultFont;}

public:
	//����Ŀ¼
	bool GetWorkDirectory(TCHAR szWorkDirectory[], WORD wBufferCount);
	//Ĭ������
	void SetDefaultFont(LPCTSTR pStrFontName, int nSize, bool bBold, bool bUnderline, bool bItalic);
	//��Դ���
	void SetResInstance(HINSTANCE hInstance){m_hResInstance = hInstance;}

public:
	//
	void AddFont(LPCTSTR pStrFontName, int nSize, bool bBold=false, bool bUnderline=false, bool bItalic=false);
	//
	HFONT GetFont(int nIndex);
	//
	HFONT GetEndFont();

	//ͼƬ����
public:
	//��ȡͼƬ
	CImageEx *GetImage(LPCTSTR lpszFileName,LPCTSTR lpszResType=NULL);
	//ɾ��ͼƬ
	void RemoveImage(CImageEx *&pImage);
	//ɾ������
	void ClearImage();

	//�滭����
public:
	//����ɫ��
	void DrawColor(HDC hDC, const RECT& rc, COLORREF color);
	//����ɫ��
	void DrawGradient(HDC hDC, const RECT& rc, DWORD dwFirst, DWORD dwSecond, bool bVertical, int nSteps);
	//��������
	void DrawLine(HDC hDC, const RECT& rc, int nSize, COLORREF dwPenColor,int nStyle = PS_SOLID);
	//���ƾ���
	void DrawRect(HDC hDC, const RECT& rc, int nSize, COLORREF dwPenColor);
	//Բ�Ǿ���
	void DrawRoundRect(HDC hDC, const RECT& rc, int width, int height, int nSize, COLORREF dwPenColor);
	//���ֳߴ�
	SIZE GetTextSize(HDC hDC, LPCTSTR pstrText, HFONT hFont, UINT uStyle);
};

#define UIRenderEngine	CUIRenderManager::GetInstance()

#endif