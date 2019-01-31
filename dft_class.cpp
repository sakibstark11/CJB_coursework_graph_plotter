#include "dft_class.h"




void dft_class::calculate_DFT(read_and_print *rpo)
{

	
	double saved_product_sum_sin_img = accumulate(rpo->yStore_product_sin_bin.begin(), rpo->yStore_product_sin_bin.end(), 0.0);
	double saved_product_sum_cos_real = accumulate(rpo->yStore_product_cos_bin.begin(), rpo->yStore_product_cos_bin.end(), 0.0);
	cout  << setprecision(4) << fixed << "DFT is "  << " - " << saved_product_sum_cos_real << "-" << saved_product_sum_sin_img << "i" << endl;
}

dft_class::dft_class()
{
}




dft_class::~dft_class()
{
}


