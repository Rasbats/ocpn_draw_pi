/***************************************************************************
 *
 * Project:  OpenCPN
 *
 ***************************************************************************
 *   Copyright (C) 2013 by David S. Register                               *
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

#ifndef __OCPNSELECT_H__
#define __OCPNSELECT_H__

#include "SelectItem.h"
#include "Path.h"
#include "OCPNSelect.h"
//#include "Select.h"
//#include "Boundary.h"

#define SELTYPE_OCPNPOINT            0x0800
#define SELTYPE_PATHSEGMENT          0x1000

class OCPNSelect
{
public:
    OCPNSelect();
    ~OCPNSelect();

    void SetSelectPixelRadius(int radius){ pixelRadius = radius; }

    bool AddSelectableOCPNPoint( float slat, float slon, OCPNPoint *pOCPNPointAdd );
    bool AddSelectablePathSegment( float slat1, float slon1, float slat2, float slon2,
            OCPNPoint *pOCPNPointAdd1, OCPNPoint *pOCPNPointAdd2, Path *pPath );

    SelectItem *FindSelection( float slat, float slon, int fseltype );
    SelectableItemList FindSelectionList( float slat, float slon, int fseltype );

    bool DeleteAllSelectablePathSegments( Path * );
    bool DeleteAllSelectableOCPNPoints( Path * );
    bool AddAllSelectablePathSegments( Path *pr );
    bool AddAllSelectableOCPNPoints( Path *pr );
    bool UpdateSelectablePathSegments( OCPNPoint *prp );
    bool IsSegmentSelected( float a, float b, float c, float d, float slat, float slon );
    bool IsSelectableSegmentSelected( float slat, float slon, SelectItem *pFindSel );

    //    Generic Point Support
    //      e.g. Tides/Currents and AIS Targets
    SelectItem *AddSelectablePoint(float slat, float slon, const void *data, int fseltype);
    bool DeleteAllPoints( void );
    bool DeleteSelectablePoint( void *data, int SeltypeToDelete );
    bool ModifySelectablePoint( float slat, float slon, void *data, int fseltype );

    //    Delete all selectable points in list by type
    bool DeleteAllSelectableTypePoints( int SeltypeToDelete );

    bool DeleteSelectableOCPNPoint( OCPNPoint *prp );
    
    //  Accessors

    SelectableItemList *GetSelectList()
    {
        return pSelectList;
    }

private:
    void CalcSelectRadius();

    SelectableItemList *pSelectList;
    int pixelRadius;
    float selectRadius;
};

#endif