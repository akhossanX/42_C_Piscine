find . -type f -name "*.sh" | rev | cut -d"/" -f1 | cut -d"." -f2- | rev
