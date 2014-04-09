#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"
OUTPUT_DIR="$DIR"
MAKE_LUABINDING="$QUICK_COCOS2DX_ROOT"/bin/compile_luabinding.sh
$MAKE_LUABINDING -E CustomerScheduler -d "$OUTPUT_DIR" CustomerScheduler_luabinding.tolua
