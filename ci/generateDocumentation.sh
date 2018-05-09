#!/bin/sh

DOXYFILE=$TRAVIS_BUILD_DIR/Doxyfile

echo "Setting up the script..."

set -e

git clone -b gh-pages https://github.com/TravorLZH/libgeneric code_docs
cd code_docs

git config --global push.default simple
git config user.name "Travis CI"
git config user.email "travis@travis-ci.org"

git reset --hard `git rev-list --max-parents=0 --abbrev-commit HEAD`

echo "" > .nojekyll

echo "Generating Doxygen code documentation..."
doxygen $DOXYFILE 2>&1 | tee doxygen.log

if [-d "docs"] && [-f "docs/index.html"]; then
	echo "Uploading documentation to the gh-pages branch..."
	git add --all
	git commit -m "Deploy Doxygen Documentations to Github Pages" -m \ "
	Travis Build: ${TRAVIS_BUILD_NUMBER} \
	Commit: ${TRAVIS_COMMIT} \
	"
	git push --force https://github.com/TravorLZH/libgeneric > /dev/null 2>&1
else
	echo ''>&2
	echo 'Warning: No documentation (html) files have been found!' >&2
	echo 'Warning: Not going to push the documentation to GitHub!' >&2
	exit 1
fi
