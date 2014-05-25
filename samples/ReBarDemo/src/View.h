//////////////////////////////////////////////////////
// View.h

#ifndef VIEW_H
#define VIEW_H



// Declaration of the CView class
class CView : public CWnd
{
public:
	CView();
	virtual ~CView(){}

//	void RecalcLayout();
//	void SetWrapState(CToolBar* pToolBar, BOOL bWrap);
//	void OnBottom();
//	void OnLeft();
//	void OnRight();
//	void OnTop();

protected:
//	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual int  OnCreate(LPCREATESTRUCT pcs);
	virtual void OnDraw(CDC* pDC);
	virtual void OnInitialUpdate();
	virtual LRESULT OnNotify(WPARAM wParam, LPARAM lParam);
	virtual void PreCreate(CREATESTRUCT &cs);
	virtual void PreRegisterClass(WNDCLASS &wc);
	virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	CMenuBar m_MenuBar;
	CReBar m_ReBar;
	CToolBar m_ToolBar;
	CImageList m_ToolBarImages;
};


#endif // VIEW_H
