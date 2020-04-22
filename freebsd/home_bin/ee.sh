#!/usr/bin/env bash
#exec /usr/bin/emacsclient --alternate-editor="" -c "$@"
exec /usr/local/bin/emacsclient -s edit -c "$@"
