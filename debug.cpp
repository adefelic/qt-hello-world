#include "debug.h"

/** debug functions **/
// thank you http://stackoverflow.com/a/36518687
void dump_props(QObject *o) {
	auto mo = o->metaObject();
	qDebug() << "## Properties of" << o << "##";
	do {
		qDebug() << "### Class" << mo->className() << "###";
		std::vector<std::pair<QString, QVariant> > v;
		v.reserve(mo->propertyCount() - mo->propertyOffset());
		for (int i = mo->propertyOffset(); i < mo->propertyCount();
					++i)
			v.emplace_back(mo->property(i).name(),
										 mo->property(i).read(o));
		std::sort(v.begin(), v.end());
		for (auto &i : v)
			qDebug() << i.first << "=>" << i.second;
		qDebug() << '\n';
	} while ((mo = mo->superClass()));
}

void dump_qml_tree(std::unique_ptr<QQuickView> &view) {
	auto objects = view->rootObject()->children();
	for (auto o : objects) dump_props(o);
}
