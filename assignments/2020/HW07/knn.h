// train_instances : stored row-major with n_train rows and n_features columns
// test_instance : single vector of length n_feaures
//
// Returns an array of length n_train where entry i is the 1-norm of the difference
// between test_instance and the i-th row of train_instances
double* compute_distances(size_t n_features,
                          const double* train_instances,
                          size_t n_train,
                          const double* test_instance);
