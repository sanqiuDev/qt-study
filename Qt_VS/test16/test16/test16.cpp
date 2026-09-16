#include "test16.h"

#include <QPluginLoader>

test16::test16(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //这次我们学习：QPluginLoader 
    /*
        QPluginLoader：Qt 专门用来加载 Qt 插件动态库 (dll/so) 的类，
        对比 QLibrary，它原生支持 Qt 元对象、QObject 插件、接口识别

        核心成员函数
            | 函数                            | 作用                                        |
            | ---   ---------------  ------   | --- -----------------------------------    |
            | QPluginLoader(QString filePath) | 构造，传入 dll 完整路径                      |
            | bool load()                     | 手动加载 dll；instance () 会隐式自动调用 load |
            | bool isLoaded()                 | 判断是否加载成功                             |

            | QObject* instance()             | 【最重要】获取插件根 QObject 实例；加载失败返回 nullptr |

            | QString errorString()           | 获取加载失败的详细错误信息（排错神器） |
            | QJsonObject metaData()          | 读取插件Q_PLUGIN_METADATA 里的 json 元数据，不用加载 dll 就能读 |
            | bool unload()                   | 卸载插件；有其他 loader 还在使用同 dll 时，卸载失败 |
    */
}

test16::~test16()
{}


// 加载单个插件dll
void loadOnePlugin(const QString& dllFullPath)
{
    QPluginLoader loader(dllFullPath);

    // 调用instance()，内部自动执行load()
    QObject* pluginObj = loader.instance();
    if (!pluginObj)
    {
        qDebug() << "插件加载失败:" << loader.errorString();
        return;
    }

    // 转成我们自定义的分光插件接口
    AbstractExpInterface* expIf = qobject_cast<AbstractExpInterface*>(pluginObj);
    if (expIf)
    {
        qDebug() << "✅分光插件加载成功";
        QWidget* w = expIf->createExpWidget();
        w->show();
    }
    else
    {
        qDebug() << "❌DLL不是Exp插件，没有实现目标接口";
        loader.unload(); //不需要就卸载
    }
}