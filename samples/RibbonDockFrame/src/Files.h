/////////////////////////////
// Files.h
//

#ifndef FILES_H
#define FILES_H


///////////////////////////////////////////////////////
// CViewFiles manages a list view control It is used as
// the view window by CContainFiles.
class CViewFiles : public CListView
{
public:
    CViewFiles();
    virtual ~CViewFiles();

protected:
    // Virtual functions that override base class functions
    virtual void InsertItems();
    virtual void OnAttach();
    virtual void OnDestroy();
    virtual LRESULT WndProc(UINT msg, WPARAM wparam, LPARAM lparam);

private:
    // Message handlers
    LRESULT OnMouseActivate(UINT msg, WPARAM wparam, LPARAM lparam);

    void SetColumns();

    // Member variables
    CImageList m_imlSmall;
};


//////////////////////////////////////////////////
// CContainFiles manages a dock container. It uses
// CViewFiles as its view.
class CContainFiles : public CDockContainer
{
public:
    CContainFiles();
    virtual ~CContainFiles() {}

private:
    CViewFiles m_viewFiles;
};


///////////////////////////////////////
// CDockFiles manages a docker. It uses
// CContainFiles as its view.
class CDockFiles : public CDocker
{
public:
    CDockFiles();
    virtual ~CDockFiles() {}

private:
    CContainFiles m_files;
};


#endif // FILES_H
