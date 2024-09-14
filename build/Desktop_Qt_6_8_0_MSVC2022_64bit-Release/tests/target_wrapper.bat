@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\devApp\Qt\6.8.0\msvc2022_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\devApp\Qt\6.8.0\msvc2022_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\devApp\Qt\6.8.0\msvc2022_64\plugins
)
%*
EndLocal
