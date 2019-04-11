more /etc/passwd \
	| sed '/^#/d' \
	| awk 'NR%2==0'\
	| cut -d":" -f1 \
	| rev | sort -r \
	| sed -n "$FT_LINE1,$FT_LINE2 p" \
	| sed '1! s/^/, /g' \
	| tr -d '\n' \
	| sed 's/$/./g'
