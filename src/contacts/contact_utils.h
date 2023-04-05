#pragma once

#include <cstddef>

namespace contacts::utils {

static const size_t NAME_IN_CONTACTS_OFFSET = 0;

static const size_t NAME_IN_CONTACTS_SIZE = 15;

static const size_t HOME_OFFSET = 0;

static const size_t WORK_OFFSET = 145;

static const size_t FAX_OFFSET = 187;

static const size_t TEL_OFFSET = 42;

static const size_t MAIL_OFFSET = 84;

static const size_t ORG_SIZE = 19;

static const size_t MAIL_SIZE = 17;

static const size_t ORG_OFFSET = 42;

static const size_t DELETED_OFFSET = 85;

static const size_t DELETED = 0xD7;

static const size_t NUMBER_SIZE = 22;

static const size_t NAME_SIZE = 42;

static const char SPACE = ' ';

auto is_email(char ch) -> bool;

auto is_valid(char ch) -> bool;

}
