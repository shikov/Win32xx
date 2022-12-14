/////////////////////////////
// Views.h
//

#ifndef VIEWS_H
#define VIEWS_H


///////////////////////////////////////
// CViewSimple manages a simple window.
class CViewSimple : public CWnd
{
public:
    CViewSimple() {}
    virtual ~CViewSimple() {}

protected:
    // Virtual functions that override base class functions
    virtual void OnDraw(CDC& dc);
    virtual LRESULT WndProc(UINT msg, WPARAM wparam, LPARAM lparam);

private:
    CViewSimple(const CViewSimple&);                // Disable copy construction
    CViewSimple& operator = (const CViewSimple&);   // Disable assignment operator
};


//////////////////////////////////////////////
// CViewText manages an edit control.
// It is used as the view window by CDockText.
class CViewText : public CWnd
{
public:
    CViewText() {}
    virtual ~CViewText() {}

protected:
    // Virtual functions that override base class functions
    virtual void OnAttach();
    virtual void PreCreate(CREATESTRUCT& cs);

private:
    CViewText(const CViewText&);                // Disable copy construction
    CViewText& operator = (const CViewText&);   // Disable assignment operator
};


//////////////////////////////////////////////
// CViewText manages a tree view control.
// It is used as the view window by CDockTree.
class CViewTree : public CTreeView
{
public:
    CViewTree();
    virtual ~CViewTree();

protected:
    // Virtual functions that override base class functions
    virtual void OnAttach();

private:
    CViewTree(const CViewTree&);                // Disable copy construction
    CViewTree& operator = (const CViewTree&);   // Disable assignment operator

    CImageList m_smallImages;
};

/////////////////////////////////////////////
// CViewList manages a list view control.
// It is used as the view window by CDockList.
class CViewList : public CListView
{
public:
    CViewList();
    virtual ~CViewList();
    void InsertItems();
    void SetColumns();

protected:
    // Virtual functions that override base class functions
    virtual void OnAttach();

private:
    CViewList(const CViewList&);                // Disable copy construction
    CViewList& operator = (const CViewList&);   // Disable assignment operator

    CImageList m_smallImages;
};

#endif // VIEWS_H
