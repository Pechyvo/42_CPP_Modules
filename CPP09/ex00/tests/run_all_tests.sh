#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
EX00_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

cd "$EX00_DIR"
make >/dev/null

echo "Running btc tests from: $SCRIPT_DIR"
echo

echo "===== 00_error_no_args ====="
../btc || true
echo

echo "===== 00_error_too_many_args ====="
../btc "$SCRIPT_DIR/01_valid_basic.txt" extra_arg || true
echo

echo "===== 00_error_input_file_not_openable ====="
../btc "$SCRIPT_DIR/does_not_exist.txt" || true
echo

UNREADABLE_FILE="$SCRIPT_DIR/unreadable_input.txt"
cat > "$UNREADABLE_FILE" << 'EOF'
date | value
2011-01-03 | 1
EOF
chmod 000 "$UNREADABLE_FILE"
echo "===== 00_error_input_file_permission_denied ====="
../btc "$UNREADABLE_FILE" || true
chmod 644 "$UNREADABLE_FILE"
rm -f "$UNREADABLE_FILE"
echo

for f in "$SCRIPT_DIR"/*.txt; do
  echo "===== $(basename "$f") ====="
  ../btc "$f" || true
  echo
done
