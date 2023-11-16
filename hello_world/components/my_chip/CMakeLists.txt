set(requires bus)

idf_component_register(
    SRC_DIRS .
    INCLUDE_DIRS "include" "."
    REQUIRES driver esp_hw_support   esp_pm
)

