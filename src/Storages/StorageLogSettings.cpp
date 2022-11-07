#include "StorageLogSettings.h"
#include <Parsers/ASTCreateQuery.h>
#include <Parsers/ASTSetQuery.h>

namespace DB
{
String getDiskName(ASTStorage & storage_def)
{
    if (storage_def.settings)
    {
        SettingsChanges changes = storage_def.settings->changes;
        for (const auto & change : changes)
            if (change.getName() == "disk")
                return change.getFieldValue().safeGet<String>();
    }
    return "default";
}

}
