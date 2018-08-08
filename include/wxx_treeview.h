// Win32++   Version 8.5.1
// Release Date: TBA
//
//      David Nash
//      email: dnash@bigpond.net.au
//      url: https://sourceforge.net/projects/win32-framework
//
//
// Copyright (c) 2005-2017  David Nash
//
// Permission is hereby granted, free of charge, to
// any person obtaining a copy of this software and
// associated documentation files (the "Software"),
// to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify,
// merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom
// the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice
// shall be included in all copies or substantial portions
// of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//
////////////////////////////////////////////////////////




#ifndef _WIN32XX_TREEVIEW_H_
#define _WIN32XX_TREEVIEW_H_

#include "wxx_wincore.h"
#include "wxx_controls.h"
#include <commctrl.h>


// Disable macros from Windowsx.h
#undef GetNextSibling
#undef GetPrevSibling

namespace Win32xx
{

    // The CTreeView class provides the functionality of a tree view control.
    class CTreeView : public CWnd
    {
    public:
        CTreeView() {}
        virtual ~CTreeView() {}
        virtual void PreRegisterClass(WNDCLASS& wc);

// Attributes
        COLORREF GetBkColor() const;
        HTREEITEM GetChild(HTREEITEM item) const;
        UINT    GetCount() const;
        HTREEITEM GetDropHiLightItem() const;
        HWND    GetEditControl() const;
        HTREEITEM GetFirstVisible() const;
        CImageList GetImageList(int imageType) const;
        UINT    GetIndent() const;
        COLORREF GetInsertMarkColor() const;
        BOOL    GetItem(TVITEM& Item) const;
        DWORD_PTR GetItemData(HTREEITEM item) const;
        int     GetItemHeight() const;
        BOOL    GetItemImage(HTREEITEM item, int& image, int& selectedImage ) const;
        BOOL    GetItemRect(HTREEITEM item, RECT& rc, BOOL isTextOnly) const;
        CString GetItemText(HTREEITEM item, UINT textMax = 260) const;
        HTREEITEM GetLastVisible() const;
        HTREEITEM GetNextItem(HTREEITEM item, UINT nCode) const;
        HTREEITEM GetNextSibling(HTREEITEM item) const;
        HTREEITEM GetNextVisible(HTREEITEM item) const;
        HTREEITEM GetParentItem(HTREEITEM item) const;
        HTREEITEM GetPrevSibling(HTREEITEM item) const;
        HTREEITEM GetPrevVisible(HTREEITEM item) const;
        HTREEITEM GetRootItem() const;
        int     GetScrollTime() const;
        HTREEITEM GetSelection() const;
        COLORREF GetTextColor() const;
        HWND    GetToolTips() const;
        UINT    GetVisibleCount() const;
        BOOL    ItemHasChildren(HTREEITEM item) const;
        COLORREF SetBkColor(COLORREF color) const;
        CImageList SetImageList(HIMAGELIST hImages, int type = TVSIL_NORMAL) const;
        void    SetIndent(int indent) const;
        BOOL    SetInsertMark(HTREEITEM item, BOOL after = TRUE) const;
        COLORREF SetInsertMarkColor(COLORREF color) const;
        BOOL    SetItem(TVITEM& itemInfo) const;
        BOOL    SetItem(HTREEITEM item, UINT mask, LPCTSTR pText, int image, int selectedImage, UINT state, UINT stateMask, LPARAM lparam) const;
        BOOL    SetItemData(HTREEITEM item, DWORD_PTR data) const;
        int     SetItemHeight(SHORT cy) const;
        BOOL    SetItemImage(HTREEITEM item, int image, int selectedImage) const;
        BOOL    SetItemText(HTREEITEM item, LPCTSTR pText) const;
        UINT    SetScrollTime(UINT scrollTime) const;
        COLORREF SetTextColor(COLORREF color) const;
        HWND    SetToolTips(HWND hToolTip) const;

// Operations
        CImageList CreateDragImage(HTREEITEM item) const;
        BOOL    DeleteAllItems() const;
        BOOL    DeleteItem(HTREEITEM item) const;
        HWND    EditLabel(HTREEITEM item) const;
        BOOL    EndEditLabelNow(BOOL cancel) const;
        BOOL    EnsureVisible(HTREEITEM item) const;
        BOOL    Expand(HTREEITEM hItem, UINT code) const;
        HTREEITEM HitTest(TVHITTESTINFO& hitInfo) const;
        HTREEITEM InsertItem(TVINSERTSTRUCT& insertInfo) const;
        BOOL    Select(HTREEITEM item, UINT flag) const;
        BOOL    SelectDropTarget(HTREEITEM item) const;
        BOOL    SelectItem(HTREEITEM item) const;
        BOOL    SelectSetFirstVisible(HTREEITEM item) const;
        BOOL    SortChildren(HTREEITEM item, BOOL recurse) const;
        BOOL    SortChildrenCB(TVSORTCB* pSortFn, BOOL recurse) const;

    private:
        CTreeView(const CTreeView&);                // Disable copy construction
        CTreeView& operator = (const CTreeView&); // Disable assignment operator

    };

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

namespace Win32xx
{

    inline void CTreeView::PreRegisterClass(WNDCLASS& wc)
    {
        // Set the Window Class
        wc.lpszClassName =  WC_TREEVIEW;
    }

// Attributes

    // Retrieves the current background color of the control.
    inline COLORREF CTreeView::GetBkColor() const
    {
        assert(IsWindow());
        return TreeView_GetBkColor( *this );
    }


    // Retrieves the first child item of the specified tree-view item.
    inline HTREEITEM CTreeView::GetChild(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_GetChild(*this, item);
    }


    // Retrieves a count of the items in a tree-view control.
    inline UINT CTreeView::GetCount() const
    {
        assert(IsWindow());
        return TreeView_GetCount( *this );
    }


    // Retrieves the tree-view item that is the target of a drag-and-drop operation.
    inline HTREEITEM CTreeView::GetDropHiLightItem() const
    {
        assert(IsWindow());
        return TreeView_GetDropHilight(*this);
    }


    // Retrieves the handle to the edit control being used to edit a tree-view item's text.
    inline HWND CTreeView::GetEditControl() const
    {
        assert(IsWindow());
        return TreeView_GetEditControl(*this);
    }


    // Retrieves the first visible item in a tree-view control window.
    inline HTREEITEM CTreeView::GetFirstVisible() const
    {
        assert(IsWindow());
        return TreeView_GetFirstVisible(*this);
    }


    // Retrieves the handle to the normal or state image list associated with a tree-view control.
    inline CImageList CTreeView::GetImageList(int imageType) const
    {
        assert(IsWindow());
        HIMAGELIST himl = TreeView_GetImageList( *this, imageType );
        return CImageList(himl);
    }


    // Retrieves the amount, in pixels, that child items are indented relative to their parent items.
    inline UINT CTreeView::GetIndent() const
    {
        assert(IsWindow());
        return TreeView_GetIndent( *this );
    }


    // Retrieves the color used to draw the insertion mark for the tree view.
    inline COLORREF CTreeView::GetInsertMarkColor() const
    {
        assert(IsWindow());
        return TreeView_GetInsertMarkColor( *this );
    }


    // Retrieves some or all of a tree-view item's attributes.
    inline BOOL CTreeView::GetItem(TVITEM& itemInfo) const
    {
        assert(IsWindow());
        return TreeView_GetItem( *this, &itemInfo );
    }


    // Retrieves a tree-view item's application data.
    inline DWORD_PTR CTreeView::GetItemData(HTREEITEM item) const
    {
        assert(IsWindow());

        TVITEM tvi;
        ZeroMemory(&tvi, sizeof(tvi));
        tvi.mask = TVIF_PARAM;
        tvi.hItem = item;
        TreeView_GetItem( *this, &tvi );
        return tvi.lParam;
    }


    // Retrieves the current height of the tree-view item.
    inline int  CTreeView::GetItemHeight() const
    {
        assert(IsWindow());
        return TreeView_GetItemHeight( *this );
    }


    // Retrieves the index of the tree-view item's image and selected image.
    inline BOOL CTreeView::GetItemImage(HTREEITEM item, int& image, int& selectedImage ) const
    {
        assert(IsWindow());

        TVITEM tvi;
        ZeroMemory(&tvi, sizeof(tvi));
        tvi.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE;
        tvi.hItem = item;
        BOOL Succeeded = TreeView_GetItem( *this, &tvi );
        image = tvi.iImage;
        selectedImage = tvi.iSelectedImage;
        return Succeeded;
    }


    // Retrieves the bounding rectangle for a tree-view item and indicates whether the item is visible.
    inline BOOL CTreeView::GetItemRect(HTREEITEM item, RECT& rc, BOOL isTextOnly) const
    {
        assert(IsWindow());
        return TreeView_GetItemRect( *this, item, &rc, isTextOnly );
    }


    // Retrieves the text for a tree-view item.
    // Note: Although the tree-view control allows any length string to be stored
    //       as item text, only the first 260 characters are displayed.
    inline CString CTreeView::GetItemText(HTREEITEM item, UINT textMax /* = 260 */) const
    {
        assert(IsWindow());

        CString str;
        if (textMax > 0)
        {
            TVITEM tvi;
            ZeroMemory(&tvi, sizeof(tvi));
            tvi.hItem = item;
            tvi.mask = TVIF_TEXT;
            tvi.cchTextMax = textMax;
            tvi.pszText = str.GetBuffer(textMax);
            SendMessage(TVM_GETITEM, 0, reinterpret_cast<LPARAM>(&tvi));
            str.ReleaseBuffer();
        }
        return str;
    }


    // Retrieves the last expanded item in a tree-view control.
    // This does not retrieve the last item visible in the tree-view window.
    inline HTREEITEM CTreeView::GetLastVisible() const
    {
        assert(IsWindow());
        return TreeView_GetLastVisible(*this);
    }


    // Retrieves the tree-view item that bears the specified relationship to a specified item.
    inline HTREEITEM CTreeView::GetNextItem(HTREEITEM item, UINT code) const
    {
        assert(IsWindow());
        return TreeView_GetNextItem( *this, item, code);
    }


    // Retrieves the next sibling item of a specified item in a tree-view control.
    inline HTREEITEM CTreeView::GetNextSibling(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_GetNextSibling(*this, item);
    }


    // Retrieves the next visible item that follows a specified item in a tree-view control.
    inline HTREEITEM CTreeView::GetNextVisible(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_GetNextVisible(*this, item);
    }


    // Retrieves the parent item of the specified tree-view item.
    inline HTREEITEM CTreeView::GetParentItem(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_GetParent(*this, item);
    }


    // Retrieves the previous sibling item of a specified item in a tree-view control.
    inline HTREEITEM CTreeView::GetPrevSibling(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_GetPrevSibling(*this, item);
    }


    // Retrieves the first visible item that precedes a specified item in a tree-view control.
    inline HTREEITEM CTreeView::GetPrevVisible(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_GetPrevVisible(*this, item);
    }


    // Retrieves the topmost or very first item of the tree-view control.
    inline HTREEITEM CTreeView::GetRootItem() const
    {
        assert(IsWindow());
        return TreeView_GetRoot(*this);
    }


    // Retrieves the maximum scroll time for the tree-view control.
    inline int CTreeView::GetScrollTime() const
    {
        assert(IsWindow());
        return TreeView_GetScrollTime( *this );
    }


    // Retrieves the currently selected item in a tree-view control.
    inline HTREEITEM CTreeView::GetSelection() const
    {
        assert(IsWindow());
        return TreeView_GetSelection(*this);
    }


    // Retrieves the current text color of the control.
    inline COLORREF CTreeView::GetTextColor() const

    {
        assert(IsWindow());
        return TreeView_GetTextColor( *this );
    }


    // Retrieves the handle to the child ToolTip control used by a tree-view control.
    inline HWND CTreeView::GetToolTips() const
    {
        assert(IsWindow());
        return TreeView_GetToolTips(*this);
    }


    // Obtains the number of items that can be fully visible in the client window of a tree-view control.
    inline UINT CTreeView::GetVisibleCount() const
    {
        assert(IsWindow());
        return TreeView_GetVisibleCount( *this );
    }


    // Returns true of the tree-view item has one or more children.
    inline BOOL CTreeView::ItemHasChildren(HTREEITEM item) const
    {
        assert(IsWindow());

        if (TreeView_GetChild( *this, item))
            return TRUE;

        return FALSE;
    }


    // Sets the background color of the control.
    inline COLORREF CTreeView::SetBkColor(COLORREF color) const
    {
        assert(IsWindow());
        return TreeView_SetBkColor( *this, color);
    }


    // Sets the normal or state image list for a tree-view control
    // and redraws the control using the new images.
    inline CImageList CTreeView::SetImageList(HIMAGELIST hImages, int type /*= TVSIL_NORMAL*/) const
    {
        assert(IsWindow());
        HIMAGELIST himl = TreeView_SetImageList( *this, hImages, type );
        return CImageList(himl);
    }


    // Sets the width of indentation for a tree-view control
    // and redraws the control to reflect the new width.
    inline void CTreeView::SetIndent(int indent) const
    {
        assert(IsWindow());
        TreeView_SetIndent( *this, indent );
    }


    // Sets the insertion mark in a tree-view control.
    inline BOOL CTreeView::SetInsertMark(HTREEITEM item, BOOL after/* = TRUE*/) const
    {
        assert(IsWindow());
        return TreeView_SetInsertMark( *this, item, after );
    }


    // Sets the color used to draw the insertion mark for the tree view.
    inline COLORREF CTreeView::SetInsertMarkColor(COLORREF color) const
    {
        assert(IsWindow());
        return TreeView_SetInsertMarkColor( *this, color );
    }


    // Sets some or all of a tree-view item's attributes.
    inline BOOL CTreeView::SetItem(TVITEM& item) const
    {
        assert(IsWindow());
        return TreeView_SetItem( *this, &item);
    }


    // Sets some or all of a tree-view item's attributes.
    inline BOOL CTreeView::SetItem(HTREEITEM item, UINT mask, LPCTSTR pText, int image, int selectedImage, UINT state, UINT stateMask, LPARAM lparam) const
    {
        assert(IsWindow());

        TVITEM tvi;
        ZeroMemory(&tvi, sizeof(tvi));
        tvi.hItem = item;
        tvi.mask  = mask;
        tvi.pszText = const_cast<LPTSTR>(pText);
        tvi.iImage  = image;
        tvi.iSelectedImage = selectedImage;
        tvi.state = state;
        tvi.stateMask = stateMask;
        tvi.lParam = lparam;
        return TreeView_SetItem( *this, &tvi );
    }


    // Sets the tree-view item's application data.
    inline BOOL CTreeView::SetItemData(HTREEITEM item, DWORD_PTR data) const
    {
        assert(IsWindow());

        TVITEM tvi;
        ZeroMemory(&tvi, sizeof(tvi));
        tvi.hItem = item;
        tvi.mask = TVIF_PARAM;
        tvi.lParam = data;
        return TreeView_SetItem( *this, &tvi );
    }


    // Sets the height of all the tree-view items.
    inline int  CTreeView::SetItemHeight(SHORT cy) const
    {
        assert(IsWindow());
        return TreeView_SetItemHeight( *this, cy );
    }


    // Sets the tree-view item's application image.
    inline BOOL CTreeView::SetItemImage(HTREEITEM item, int image, int selectedImage) const
    {
        assert(IsWindow());

        TVITEM tvi;
        ZeroMemory(&tvi, sizeof(tvi));
        tvi.hItem = item;
        tvi.iImage = image;
        tvi.iSelectedImage = selectedImage;
        tvi.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE;
        return TreeView_SetItem(*this, &tvi );
    }


    // Sets the tree-view item's application text.
    inline BOOL CTreeView::SetItemText(HTREEITEM item, LPCTSTR pText) const
    {
        assert(IsWindow());

        TVITEM tvi;
        ZeroMemory(&tvi, sizeof(tvi));
        tvi.hItem = item;
        tvi.pszText = const_cast<LPTSTR>(pText);
        tvi.mask = TVIF_TEXT;
        return TreeView_SetItem(*this, &tvi );
    }


    // Sets the maximum scroll time for the tree-view control.
    inline UINT CTreeView::SetScrollTime(UINT scrollTime) const
    {
        assert(IsWindow());
        return TreeView_SetScrollTime( *this, scrollTime );
    }


    // Sets the text color of the control.
    inline COLORREF CTreeView::SetTextColor(COLORREF color) const
    {
        assert(IsWindow());
        return TreeView_SetTextColor( *this, color );
    }


    // Sets a tree-view control's child ToolTip control.
    inline HWND CTreeView::SetToolTips(HWND hToolTip) const
    {
        assert(IsWindow());
        return TreeView_SetToolTips(*this, hToolTip);
    }

    // Operations


    // Creates a dragging bitmap for the specified item in a tree-view control.
    // It also creates an image list for the bitmap and adds the bitmap to the image list.
    // An application can display the image when dragging the item by using the image list functions.
    inline CImageList CTreeView::CreateDragImage(HTREEITEM item) const
    {
        assert(IsWindow());
        HIMAGELIST himl = TreeView_CreateDragImage(*this, item);
        return CImageList(himl);
    }


    // Deletes all items from a tree-view control.
    inline BOOL CTreeView::DeleteAllItems() const
    {
        assert(IsWindow());
        return TreeView_DeleteAllItems( *this );
    }


    // Removes an item and all its children from a tree-view control.
    inline BOOL CTreeView::DeleteItem(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_DeleteItem( *this, item);
    }


    // Begins in-place editing of the specified item's text, replacing the text of the item
    // with a single-line edit control containing the text.
    // The specified item  is implicitly selected and focused.
    inline HWND CTreeView::EditLabel(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_EditLabel( *this, item);
    }


    // Ends the editing of a tree-view item's label.
    inline BOOL CTreeView::EndEditLabelNow(BOOL cancel) const
    {
        assert(IsWindow());
        return TreeView_EndEditLabelNow(*this, cancel);
    }


    // Ensures that a tree-view item is visible, expanding the parent item or
    // scrolling the tree-view control, if necessary.
    inline BOOL CTreeView::EnsureVisible(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_EnsureVisible( *this, item);
    }


    // The TreeView_Expand macro expands or collapses the list of child items associated
    // with the specified parent item, if any.
    inline BOOL CTreeView::Expand(HTREEITEM item, UINT code) const
    {
        assert(IsWindow());
        return TreeView_Expand( *this, item, code );
    }


    // Determines the location of the specified point relative to the client area of a tree-view control.
    inline HTREEITEM CTreeView::HitTest(TVHITTESTINFO& hitInfo) const
    {
        assert(IsWindow());
        return TreeView_HitTest( *this, &hitInfo );
    }


    // Inserts a new item in a tree-view control.
    inline HTREEITEM CTreeView::InsertItem(TVINSERTSTRUCT& insertInfo) const
    {
        assert(IsWindow());
        return TreeView_InsertItem( *this, &insertInfo );
    }


    // Selects the specified tree-view item, scrolls the item into view, or redraws
    // the item in the style used to indicate the target of a drag-and-drop operation.
    inline BOOL CTreeView::Select(HTREEITEM item, UINT flag) const
    {
        assert(IsWindow());
        return TreeView_Select(*this, item, flag );
    }


    // Redraws a specified tree-view control item in the style used to indicate the
    // target of a drag-and-drop operation.
    inline BOOL CTreeView::SelectDropTarget(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_SelectDropTarget(*this, item);
    }


    // Selects the specified tree-view item.
    inline BOOL CTreeView::SelectItem(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_SelectItem(*this, item);
    }


    // Scrolls the tree-view control vertically to ensure that the specified item is visible.
    // If possible, the specified item becomes the first visible item at the top of the control's window.
    inline BOOL CTreeView::SelectSetFirstVisible(HTREEITEM item) const
    {
        assert(IsWindow());
        return TreeView_SelectSetFirstVisible(*this, item);
    }


    // Sorts the child items of the specified parent item in a tree-view control.
    inline BOOL CTreeView::SortChildren(HTREEITEM item, BOOL recurse) const
    {
        assert(IsWindow());
        return TreeView_SortChildren( *this, item, recurse );
    }


    // Sorts tree-view items using an application-defined callback function that compares the items.
    inline BOOL CTreeView::SortChildrenCB(TVSORTCB* pSortFn, BOOL recurse) const
    {
        assert(IsWindow());
        return TreeView_SortChildrenCB( *this, pSortFn, recurse );
    }


} // namespace Win32xx

#endif // #ifndef _WIN32XX_TREEVIEW_H_

