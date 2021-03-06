/****************************************************************************
 **
 **  Copyright (C) 2015 Andreas Mussgiller
 **
 **  This program is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 **
 ****************************************************************************/

#include "nline2D.h"

NLine2D::NLine2D(const NPoint2D& point, const NDirection2D& direction)
: point_(point),
  direction_(direction)
{

}

NLine2D::NLine2D(const NLine2D& other)
: point_(other.point()),
  direction_(other.direction())
{

}

NLine2D::~NLine2D()
{

}

NPoint2D NLine2D::pointAt(double s)
{
  NPoint2D p(point());
  p.move(direction().x()*s,
         direction().y()*s);
  return p;
}
