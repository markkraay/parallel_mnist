#include "util/img.h"
#include "neural/activations.h"
#include "neural/nn.h"
#include "matrix/matrix.h"
#include "matrix/ops.h"

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));

	//TRAINING
	int n_train_imgs = 10000;
	Img** train_imgs = csv_to_imgs("data/mnist_train.csv", n_train_imgs);
	NeuralNetwork* net = network_create(784, 300, 10, 0.1);
	network_train_batch_imgs(net, train_imgs, n_train_imgs);
	// network_save(net, "testing_net");

	// PREDICTING
	int n_test_imgs = 3000;
	Img** test_imgs = csv_to_imgs("data/mnist_test.csv", n_test_imgs);
	// NeuralNetwork* net = network_load("testing_net");
	double score = network_predict_imgs(net, test_imgs, 1000);
	printf("Score: %1.5f\n", score);

	imgs_free(train_imgs, n_train_imgs);
	imgs_free(test_imgs, n_test_imgs);
	network_free(net);
	return 0;
}