package im.actor.server.persist.contact

import im.actor.server.models

import scala.concurrent.ExecutionContext
import scala.util.{ Success, Failure }

import slick.dbio.DBIO
import slick.driver.PostgresDriver.api._

class UserContact(tag: Tag) extends Table[models.contact.UserContact](tag, "user_contacts") {
  def ownerUserId = column[Int]("owner_user_id", O.PrimaryKey)
  def contactUserId = column[Int]("contact_user_id", O.PrimaryKey)
  def phoneNumber = column[Long]("phone_number")
  def name = column[Option[String]]("name")
  def accessSalt = column[String]("access_salt")
  def isDeleted = column[Boolean]("is_deleted")

  def * = (ownerUserId, contactUserId, phoneNumber, name, accessSalt, isDeleted) <> (models.contact.UserContact.tupled, models.contact.UserContact.unapply)
}

object UserContact {
  val contacts = TableQuery[UserContact]

  def byPK(ownerUserId: Int, contactUserId: Int) =
    contacts.filter(c => c.ownerUserId === ownerUserId && c.contactUserId === contactUserId)

  def byPKNotDeleted(ownerUserId: Int, contactUserId: Int) =
    contacts.filter(c => c.ownerUserId === ownerUserId && c.contactUserId === contactUserId && c.isDeleted === true)

  def byPKDeleted(ownerUserId: Int, contactUserId: Int) =
    contacts.filter(c => c.ownerUserId === ownerUserId && c.contactUserId === contactUserId && c.isDeleted === true)

  def find(ownerUserId: Int, contactUserId: Int) =
    byPKNotDeleted(ownerUserId, contactUserId).result.headOption

  def createOrRestore(ownerUserId: Int, contactUserId: Int, phoneNumber: Long, name: Option[String], accessSalt: String) = {
    val contact = models.contact.UserContact(ownerUserId, contactUserId, phoneNumber, name, accessSalt, false)
    contacts.insertOrUpdate(contact)
  }
}
