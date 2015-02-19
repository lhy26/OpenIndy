#ifndef OBSERVATIONMODEL_H
#define OBSERVATIONMODEL_H

#include <QAbstractTableModel>
#include "feature.h"
#include "featurewrapper.h"
#include "QStringList"
//#include "oifeaturestate.h"
#include "guiconfiguration.h"
#include "featureupdater.h"

/*!
 * \brief The ObservationModel class handles to display all information and attributes about the observations of the selected feature
 */
class ObservationModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ObservationModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

signals:

    void resizeView();
    void recalcFeature();

public slots:
    void updateModel();
};

#endif // OBSERVATIONMODEL_H