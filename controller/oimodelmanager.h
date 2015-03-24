#ifndef OIMODELMANAGER_H
#define OIMODELMANAGER_H

#include <QObject>
#include <QPointer>

#include "oijob.h"






#include <QMap>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QSerialPortInfo>
#include <QHostAddress>
#include <QNetworkInterface>

#include "systemdbmanager.h"
#include "featuretablemodel.h"
#include "featuretableproxymodel.h"

class OiModelManager : public QObject
{
    Q_OBJECT

private:
    explicit OiModelManager(QObject *parent = 0);

public:

    //############################
    //get or set the current OiJob
    //############################

    static const QPointer<OiJob> &getCurrentJob();
    static void setCurrentJob(const QPointer<OiJob> &job);

    //#########################################
    //static models (models that may be reused)
    //#########################################

    //general feature models
    static FeatureTableModel &getFeatureTableModel();
    static FeatureTableProxyModel &getFeatureTableProxyModel();




    /*
    static QStringListModel &getPluginNamesModel();
    //static PluginTreeViewModel &getPluginTreeViewModel();
    static QSqlQueryModel &getCreateFunctionsModel();
    static QSqlQueryModel &getChangeFunctionsModel();
    static QSqlQueryModel &getSensorsModel(SensorTypes typeOfSensor);

    static QStringListModel &getCoordinateSystemsModel();
    static QStringListModel &getNominalSystemsModel();

    static QStringListModel &getGeometryTypesModel();

    static QStandardItemModel &getSensorTypes();
    static QStandardItemModel &getBaudRateTypes();
    static QStandardItemModel &getDataBitTypes();
    static QStandardItemModel &getFlowControlTypes();
    static QStandardItemModel &getParityTypes();
    static QStandardItemModel &getStopBitTypes();
    static QStandardItemModel &getAvailableSerialPorts();
    static QStandardItemModel &getAvailableIpAdresses();

    static QStringListModel &getDistanceUnitsModel();
    static QStringListModel &getAngleUnitsModel();
    static QStringListModel &getTemperatureUnitsModel();

    static QStringListModel &getGroupNamesModel();

    static FeatureTableModel &getFeatureTableModel();
    static FeatureTableProxyModel &getFeatureTableProxyModel();
    //static TrafoParamProxyModel &getTrafoParamProxyModel();
    //static FeatureTreeViewModel &getFeatureTreeViewModel();
    //static FeatureGraphicsTreeViewProxyModel &getFeatureGraphicsModel();*/

    //##########################################################
    //dynamic models (models that cannot or shall not be shared)
    //##########################################################

    //static GeometryTypesProxyModel *getGeometryTypesFilterModel();



    //static QStringListModel *getSimpleAsciiExchangePlugins(QString plugin);
    //static QStringListModel getDefinedFormatExchangePlugins();

    //static AvailableElementsTreeViewProxyModel *getAvailableElementsModel(Configuration::ElementTypes filter);
    //static UsedElementsModel *getUsedElementsModel(int functionIndex, int elementIndex);

    //static QStandardItemModel *getFunctionTreeViewModel();

private slots:
    /*void featureSetChanged();
    void activeFeatureChanged();
    void activeStationChanged();
    void activeCoordinateSystemChanged();
    void availableGroupsChanged();
    void coordSystemSetChanged();
    void featuresRecalculated();*/

private:

    static QPointer<OiJob> currentJob;

    //#############
    //static models
    //#############

    //general feature models
    static FeatureTableModel featureTableModel;
    static FeatureTableProxyModel featureTableProxyModel;



    //initialize and connect all models provided by OiModelManager
    void initModels();

    /*void connectModels();

    //helper methods to initialize the different model types
    void initSensorModels();
    void initCoordinateSystemModels();
    void initUnitModels();
    void initGroupNameModels();
    void initPluginModels();*/



    /*
    //general feature models
    static FeatureTableModel featureTableModel;
    static FeatureTableProxyModel featureTableProxyModel;
    //static TrafoParamProxyModel trafoParamProxyModel;
    //static FeatureTreeViewModel featureTreeViewModel;




    static QStringListModel pluginNamesModel;
    static QStringListModel coordinateSystemsModel;
    static QStringListModel nominalSystemsModel;
    static QStringListModel geometryTypes;
    static QStandardItemModel sensorTypes;
    static QStandardItemModel baudRateTypes;
    static QStandardItemModel dataBitTypes;
    static QStandardItemModel flowControlTypes;
    static QStandardItemModel parityTypes;
    static QStandardItemModel stopBitTypes;
    static QStandardItemModel availableSerialPorts;
    static QStandardItemModel availableIpAdresses;
    static QStringListModel distanceUnitsModel;
    static QStringListModel angleUnitsModel;
    static QStringListModel temperatureUnitsModel;
    static QStringListModel groupNamesModel;




    //static FeatureGraphicsTreeViewProxyModel featureGraphicsModel;
    //static PluginTreeViewModel pluginTreeViewModel;
    static QSqlQueryModel createFeatureFunctionsModel;
    static QSqlQueryModel changeFeatureFunctionsModel;
    static QSqlQueryModel laserTrackerModel;
    static QSqlQueryModel totalStationModel;
    static QSqlQueryModel undefinedSensorModel;




*/

    //TODO think about a way to manage models (delete them when not necessary)
};

#endif // OIMODELMANAGER_H
