#pragma once
#include "ArrayTransformer.h"
#include "CriteriaTransformer.h"
#include "ReplaceTransformer.h"
#include "ScalarTransformer.h"
#include "SwapTransformer.h"

ArrayTransformer* arrayFactory(Transformer type) {
	switch (type)
	{
	case Transformer::criteria:
		return new CriteriaTransformer<T>();
		break;
	case Transformer::replace:
		return new ReplaceTransformer();
		break;
	case Transformer::scalar:
		return new ScalarTransformer();
		break;
	case Transformer::swap:
		return new SwapTransformer();
		break;
	default:
		break;
	}
}