/******************************************************************************
 * $Id: ocpn_draw_pi.h,v 1.0 2015/01/28 01:54:37 jongough Exp $
 *
 * Project:  OpenCPN
 * Purpose:  OpenCPN General Drawing Plugin
 * Author:   Jon Gough
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
 *   $EMAIL$   *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#ifndef _OCPNDRAWPI_H_
#define _OCPNDRAWPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers


#include "version.h"
#include "ocpn_plugin.h"
#include "undo.h"
#include "OCPNPoint.h"
#include "OCPNDrawConfig.h"
#include "pathmanagerdialog.h"

#include "georef.h"
#include "statwin.h"

#include <wx/aui/aui.h>
#include <wx/string.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include <wx/splitter.h>
#include <wx/fileconf.h>
#include <wx/dynarray.h>

#include "wx/jsonwriter.h"
//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define OCPN_DRAW_POSITION -1

class Boundary;
class BoundaryProp;

class ocpn_draw_pi : public opencpn_plugin_113
{
public:

    ocpn_draw_pi(void *ppimgr);
    ~ocpn_draw_pi();

    bool				dlgShow;
    wxWindow            *m_parent_window;
    //wxFileConfig		*m_pconfig;
    OCPNDrawConfig		*m_pconfig;
    wxTimer 		    *m_timer;
    wxColour			col,col1,gridline,uitext,udkrd,back_color,text_color;
    wxColour			mcol,mcol1,mgridline, muitext,mudkrd,mback_color,mtext_color;
    wxString			lastWaypointInRoute;

    wxLocale*		local;
    int				state;
    bool			eventsEnabled;
    int             m_iCallerId;
    bool            m_bBoundaryEditing;


    //    The required PlugIn Methods
    int Init(void);
    bool DeInit(void);

    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();
    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    wxBitmap *GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();
    void UpdateAuiStatus(void);
//    void SetColorScheme(PI_ColorScheme cs);
    void GetOriginalColors();
    void SetOriginalColors();
    


 

    //    The optional method overrides

    void OnContextMenuItemCallback(int id);
    void latlong_to_chartpix(double lat, double lon, double &pixx, double &pixy);

    //    The required override PlugIn Methods
    //     bool RenderOverlay(wxMemoryDC *pmdc, PlugIn_ViewPort *vp);
    //      void SetCursorLatLon(double lat, double lon);


    void SetDefaults(void);
    int GetToolbarToolCount(void);
    void ShowPreferencesDialog( wxWindow* parent );
    void OnToolbarToolCallback(int id);
    void SetPluginMessage(wxString &message_id, wxString &message_body);

    void loadLayouts(wxWindow * parent);
//    void startLogbook();
    void shutdown(bool menu);
    
    bool MouseEventHook( wxMouseEvent &event );
    bool KeyboardEventHook( wxKeyEvent &event );
    void SetCursorLatLon(double lat, double lon);
    void SetCurrentViewPort(PlugIn_ViewPort &vp);
    //bool RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp);
    bool RenderOverlay(wxMemoryDC *pmdc, PlugIn_ViewPort *vp);
    bool RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp);
    wxString FormatDistanceAdaptive( double distance );
    void DrawAllPathsInBBox(ocpnDC &dc,  LLBBox& BltBBox);
    
    void RenderPathLegs( ocpnDC &dc );

    wxCursor    *pCursorLeft;
    wxCursor    *pCursorRight;
    wxCursor    *pCursorUp;
    wxCursor    *pCursorDown;

    wxCursor    *pCursorUpLeft;
    wxCursor    *pCursorUpRight;
    wxCursor    *pCursorDownLeft;
    wxCursor    *pCursorDownRight;
    wxCursor    *pCursorPencil;
    wxCursor    *pCursorArrow;
    wxCursor    *pCursorCross;
    
    int         nConfig_State;
    
    int         nBoundary_State;
    Boundary    *m_pMouseBoundary;
    wxPoint     r_rband;
    double      m_dStartLat;
    double      m_dStartLon;
    double      m_cursor_lon, m_cursor_lat;
    double      m_prev_rlat, m_prev_rlon;
    double      m_true_scale_ppm;
    OCPNPoint   *m_prev_pMousePoint;
    bool           m_disable_edge_pan;
    double      m_lat, m_lon;
    double      m_pixx, m_pixy;
    
    Undo        *undo;
    
    PlugIn_ViewPort *m_vp;
    wxGLContext     *pcontext;
    wxMemoryDC      *pmdc;


private:
    void    OnTimer(wxTimerEvent& ev);
    void	SaveConfig();
    void	LoadConfig();
    void    build_cursors();
    bool    SetCursor(const wxCursor &c);
    void    RenderExtraBoundaryLegInfo( ocpnDC &dc, wxPoint ref_point, wxString s );
    void    FinishBoundary();
//    ArrayOfGridColWidth	readCols(ArrayOfGridColWidth ar, wxString str);
//    void					writeCols(wxFileConfig *pConf, ArrayOfGridColWidth ar, wxString entry);
//    ArrayOfGridColWidth	readColsOld(wxFileConfig *pConf, ArrayOfGridColWidth ar, wxString entry);
    void					dialogDimmer(PI_ColorScheme cs,wxWindow* ctrl,wxColour col,wxColour col1, wxColour back_color,wxColour text_color, wxColour uitext, wxColour udkrd);
//    wxAuiManager     *m_pauimgr;

    bool    CreateBoundaryLeftClick(wxMouseEvent &event);
    int               m_show_id;
    int               m_hide_id;
    bool				show;
    int				m_leftclick_config_id;
    int				m_leftclick_boundary_id;

    bool              m_bLOGShowIcon;
    StatWin                   *stats;
    ColorScheme               global_color_scheme;
    
    OCPNPoint  *m_pSelectedBoundary;
    OCPNPoint  *m_pFoundOCPNPointSecond;
    
    bool        m_bDrawingBoundary;



};


#endif


