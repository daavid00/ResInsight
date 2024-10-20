#pragma once

#include <QDialog>

namespace caf
{
class PdmObject;
class PdmUiPropertyView;
} // namespace caf

class QDialogButtonBox;
class QWidget;
class QString;

namespace caf
{
class PdmUiTabbedPropertyViewDialog : public QDialog
{
public:
    PdmUiTabbedPropertyViewDialog( caf::PdmObject*    object,
                                   const QStringList& uiConfigNameForTabs,
                                   const QString&     windowTitle,
                                   QWidget*           parent );
    ~PdmUiTabbedPropertyViewDialog() override;

    QDialogButtonBox* dialogButtonBox();

protected:
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

private:
    std::vector<PdmUiPropertyView*> m_propertyViewTabs;
    QDialogButtonBox*               m_dialogButtonBox;
};

} // namespace caf
