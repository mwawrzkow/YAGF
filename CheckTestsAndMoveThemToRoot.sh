mkdir test
cp -r build/Engine/tests . 
cd tests
ctest -D ExperimentalTest --no-compress-output
mkdir Engine
xsltproc ctest-to-junit.xsl Testing/`head -n 1 < Testing/TAG`/Test.xml > Engine/result.xml
rm -rf Testing 
cd .. 
# find . -type f -name '*.xml' -exec cp {} ../../../../test \;