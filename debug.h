#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <QObject>
#include <QQuickView>
#include <QQuickItem>
#include <memory>

void dump_props(QObject *o);
void dump_qml_tree(std::unique_ptr<QQuickView> &view);

#endif