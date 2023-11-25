/***************************************************************************
 * 
 * Project:  OpenCPN
 * Purpose:  ODPath Properties Support
 * Author:   Jon Gough
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/

#ifndef __PathAndPointManagerDialogImpl__
#define __PathAndPointManagerDialogImpl__

/**
@file
Subclass of PathAndPointManagerDialogDef, which is generated by wxFormBuilder.
*/

#include "PathAndPointManagerDialogDef.h"
#include "ODPlatform.h"

//// end generated include
enum {
    SORT_ON_DISTANCE  = 1,
    SORT_ON_NAME
};

enum TrackContextMenu {
    TRACK_MERGE  = 1,
    TRACK_COPY_TEXT,
    TRACK_CLEAN
};

enum {
    PATH_TAB = 0,
    POINT_TAB,
    LAYER_TAB
};

// Forward declaration
class   ODPath;
class   ODPoint;
class   ODLayer;

/** Implementing PathAndPointManagerDialogDef */
class PathAndPointManagerDialogImpl : public PathAndPointManagerDialogDef
{
    private:
        void MakeAllPathsInvisible(void);  // Mark all boundaries as invisible. Does not flush settings.
        void ZoomtoPath(ODPath *path); // Attempt to zoom path into the view
        void UpdatePathButtons();
        void UpdateODPointButtons();
        void UpdateLayerButtons();           // Correct button state
        void ToggleLayerContentsOnChart(ODLayer *layer);
        void ToggleLayerContentsOnListing(ODLayer *layer);
        void ToggleLayerContentsNames(ODLayer *layer);
        void DeSelectPaths( void );
        void DeSelectODPoints( void );
        void SetImportButtonText( void );
        void CreateLayer( bool );
        
        bool m_bCtrlDown;         // record control key state for some action buttons
        
        int m_lastODPointItem;
        int m_lastPathItem;
        
        int m_iPage;
        int m_CharWidth;
        int m_CharHeight;

        wxFont *m_dialogLabelFont;

        wxWindow *m_parent_window;

        ODColourPickerCtrl *m_ODcolourPickerLineColour;
        
    protected:
        // Handlers for PathAndPointManagerDialogDef events.
        void OnTabSwitch( wxNotebookEvent& event );
        void OnPathToggleVisibility( wxMouseEvent& event );
        void OnPathColumnClicked( wxListEvent& event );
        void OnPathDefaultAction( wxListEvent& event );
        void OnPathDeSelected( wxListEvent& event );
        void OnPathRightClick( wxListEvent& event );
        void OnPathSelected( wxListEvent& event );
        void OnPathPropertiesClick( wxCommandEvent& event );
        void OnPathActivateClick( wxCommandEvent& event );
        void OnPathButtonLeftDown( wxMouseEvent& event );
        void OnPathCenterViewClick( wxCommandEvent& event );
        void OnPathDeleteClick( wxCommandEvent& event );
        void OnPathExportSelectedClick( wxCommandEvent& event );
        void OnPathDeleteAllClick( wxCommandEvent& event );
        void OnODPointToggleVisibility( wxMouseEvent& event );
        void OnODPointColumnClick( wxListEvent& event );
        void OnODPointDefaultAction( wxListEvent& event );
        void OnODPointDeSelected( wxListEvent& event );
        void OnODPointRightClick( wxListEvent& event );
        void OnODPointSelected( wxListEvent& event );
        void OnODPointNewClick( wxCommandEvent& event );
        void OnODPointPropertiesClick( wxCommandEvent& event );
        void OnODPointCenterViewClick( wxCommandEvent& event );
        void OnODPointDeleteClick( wxCommandEvent& event );
        void OnODPointExportSecectedClick( wxCommandEvent& event );
        void OnODPointDeleteAllClick( wxCommandEvent& event );
        void OnLayerToggleVisibility( wxMouseEvent& event );
        void OnLayerColumnClick( wxListEvent& event );
        void OnLayerDefaultAction( wxListEvent& event );
        void OnLayerRightClick( wxListEvent& event );
        void OnLayerSelected( wxListEvent& event );
        void OnLayerTemporaryClick( wxCommandEvent& event );
        void OnLayerPersistentClick( wxCommandEvent& event );
        void OnLayerDeleteClick( wxCommandEvent& event );
        void OnLayerShowOnChartClick( wxCommandEvent& event );
        void OnLayerShowPointNamesClick( wxCommandEvent& event );
        void OnLayerListContentsClick( wxCommandEvent& event );
        void OnImportClick( wxCommandEvent& event );
        void OnExportAllVisibleClick( wxCommandEvent& event );
        void OnOKClick( wxCommandEvent& event );
        void OnClose( wxCloseEvent& event );

    public:
        PathAndPointManagerDialogImpl();
        PathAndPointManagerDialogImpl(wxWindow* parent);
        virtual ~PathAndPointManagerDialogImpl();
        
        void SetColorScheme( void );
        void UpdatePathListCtrl( bool b_retain_selection = true );     // Rebuild path list
        void UpdateODPointsListCtrl(ODPoint *rp_select = NULL, bool b_retain_sort = false);
        void UpdateLayerListCtrl( void );
        void UpdateODPointListCtrlViz( void );
        void SelectedPathToggleVisibility( bool visible );
        void SelectedODPointToggleVisibility( bool visible );
        void SelectedLayerToggleVisibility( bool visible );
        void UpdatePointListCtrl(ODPoint *rp_select = NULL, bool b_retain_sort = false);
        void UpdateODPointsListCtrlViz( void );
        void RecalculateSize();

        static void ODPointShowPropertiesDialog( ODPoint* wp, wxWindow* parent );
        void ShowPathPropertiesDialog ( ODPath *path );
        static wxString GetLayerName( int id );

};

#endif // __PathAndPointManagerDialogImpl__
