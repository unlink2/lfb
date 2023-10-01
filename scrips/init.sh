#!/bin/bash

# rename to project specific values
NAME="lfb"
CONST="lfb"
STRUCT="lfb"
FN="lfb"

# will be replaced
lfb_NAME="lfb"
lfb_STRUCT="lfb"
lfb_CONST="lfb"
lfb_FN="lfb"

function replace() {
	echo "Replacing $1 with $2"
	find ./ -type f -name '*.c' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.h' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.md' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.lua' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.sh' -exec sed -i "s/$1/$2/g" {} \;
	find ./doc/ -type f -name '*' -exec sed -i "s/$1/$2/g" {} \;
}

replace $lfb_NAME $NAME
replace $lfb_CONST $CONST
replace $lfb_STRUCT $STRUCT
replace $lfb_FN $FN

mv "include/$lfb_NAME.h" "include/$NAME.h"
mv "src/$lfb_NAME.c" "src/$NAME.c"
mv "doc/$lfb_NAME" "doc/$NAME" 
