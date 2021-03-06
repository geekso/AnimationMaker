/****************************************************************************
** Copyright (C) 2016 Olaf Japp
**
** This file is part of AnimationMaker.
**
**  AnimationMaker is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  AnimationMaker is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include "rectangle.h"
#include <QtTest/QTest>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include "animationscene.h"

Rectangle::Rectangle(qreal width, qreal height, AnimationScene *scene, bool isSceneRect)
    : AnimationItem(scene, isSceneRect)
{
    setRect(0, 0, width, height);
}

int Rectangle::type() const
{
    return Rectangle::Type;
}

QDomElement Rectangle::getXml(QDomDocument doc)
{
    QDomElement ele = doc.createElement("Rectangle");
    writeAttributes(ele);
    ele.setAttribute("pen", pen().color().name());
    ele.setAttribute("brush", brush().color().name());
    return ele;
}

void Rectangle::paint( QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    paint->setPen(pen());
    paint->setBrush(brush());
    paint->drawRect(rect());

    if (option->state & QStyle::State_Selected)
        drawHighlightSelected(paint, option);
}
