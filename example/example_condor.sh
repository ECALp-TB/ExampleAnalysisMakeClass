
#to run the script, you require to arguments
# source example_condor.sh "argument1" argument2
# argument1= string
# argument2= integer

input_file=$1
input_n=$2

mkdir -p steer/
mkdir -p log/

local=$PWD

cat > ${local}/steer/test_condor.sh <<EOF
source /cvmfs/ilc.desy.de/sw/x86_64_gcc82_centos7/v02-02-03/init_ilcsoft.sh
root -l -q ${local}/Example.cc\(\"$input_file\",$input_n\)
EOF

cat > ${local}/steer/test_condor.sub <<EOF
# Unix submit description file
# kt_xNAMEfile.sub -- simple Marlin job
executable              = ${local}/steer/test_condor.sh
log                     = ${local}/log/test_condor.log
output                  = ${local}/log/outfile_test_condor.txt
error                   = ${local}/log/errors_test_condor.txt
should_transfer_files   = Yes
when_to_transfer_output = ON_EXIT
queue 1
EOF

condor_submit ${local}/steer/test_condor.sub
	



