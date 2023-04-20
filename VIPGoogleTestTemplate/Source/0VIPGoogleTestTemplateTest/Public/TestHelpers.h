#pragma once

#include "gmock/gmock.h"

MATCHER_P(ArrayHasSize, other, "Array has size"){
	return arg.Num() == other;
}
// call as:
// EXPECT_CALL(*MockEnvironmentService, DownloadEnvironments(ArrayHasSize(7))
