CREATE TABLE IF NOT EXISTS "login_info" (
  "id" INTEGER NOT NULL,
  "name" TEXT(100) NOT NULL,
  "secret_id" TEXT(100) NOT NULL,
  "secret_key" TEXT(100) NOT NULL,
  "remark" TEXT(200),
  "timestamp" integer NOT NULL,
  PRIMARY KEY ("id"),
  CONSTRAINT "secret_id" UNIQUE ("secret_id" ASC),
  CONSTRAINT "name" UNIQUE ("name" ASC)
);